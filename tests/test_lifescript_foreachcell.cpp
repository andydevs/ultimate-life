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