#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <lifescript/lifescript2.h>
#include <iostream>
#include <vector>

using namespace std;
using namespace ul::ls;
using namespace ::testing;

class MockCellFunctional : public CellFunctional
{
public:
    ~MockCellFunctional() override {};
    MOCK_METHOD(void, receive, (cell c), (override));
};

#define CELL(x, y) LSElem { .prefabbed = false, .prefab_name = "", .elem_cell = cell(x, y) }
#define PREFAB(name, x, y) LSElem { .prefabbed = true, .prefab_name = name, .elem_cell = cell(x, y) }

TEST(TestLifeScriptForeachCell, TestWithCells) {
    LifeScript2 ls;
    MockCellFunctional f;
    
    ls.add_elem(CELL(0, 10));
    ls.add_elem(CELL(10, 10));
    ls.add_elem(CELL(10, 100));
    
    EXPECT_CALL(f, receive(cell(0, 10)));
    EXPECT_CALL(f, receive(cell(10, 10)));
    EXPECT_CALL(f, receive(cell(10, 100)));

    // Run foreach cell
    ls.foreach_cell(f);
}

TEST(TestLifeScriptForeachCell, TestPrefab) {
    LifeScript2 ls;
    MockCellFunctional f;

    vector<LSElem> subelems;
    subelems.push_back(CELL(3, 4));
    subelems.push_back(CELL(-3, 2));
    ls.add_prefab("testprefab", subelems);

    ls.add_elem(CELL(10, 10));
    ls.add_elem(PREFAB("testprefab", 40, 30));

    EXPECT_CALL(f, receive(cell(10, 10)));
    EXPECT_CALL(f, receive(cell(43, 34)));
    EXPECT_CALL(f, receive(cell(37, 32)));

    ls.foreach_cell(f);
}

TEST(TestLifeScriptForeachCell, TestNestedPrefab) {
    LifeScript2 ls;
    MockCellFunctional f;

    vector<LSElem> subsubelems;
    subsubelems.push_back(CELL(-1,-1));
    subsubelems.push_back(CELL(-1,0));
    subsubelems.push_back(CELL(-1,1));
    ls.add_prefab("testsubprefab", subsubelems);

    vector<LSElem> subelems;
    subelems.push_back(CELL(3, 4));
    subelems.push_back(PREFAB("testsubprefab", -3, 9));
    ls.add_prefab("testprefab", subelems);

    ls.add_elem(CELL(10, 10));
    ls.add_elem(PREFAB("testprefab", 40, 30));

    EXPECT_CALL(f, receive(cell(10, 10)));
    EXPECT_CALL(f, receive(cell(43, 34)));
    EXPECT_CALL(f, receive(cell(36, 38))); // 40 30 -> 37 39 -> 36 38
    EXPECT_CALL(f, receive(cell(36, 39))); // 40 30 -> 37 39 -> 36 39
    EXPECT_CALL(f, receive(cell(36, 40))); // 40 30 -> 37 39 -> 36 40

    ls.foreach_cell(f);
}