#include <gtest/gtest.h>
#include <lifescript/celliterator.h>
#include <lifescript/lifescript.h>

using namespace ul::ls;

TEST(CellIteratorTest, Initialize) {
    LifeScript ls;
    std::unique_ptr<cell_iterator> it(new cell_iterator(ls));
}