#include <gtest/gtest.h>
#include <utils/range.h>

using namespace ul::utils;

TEST(int_range_iterator, test_with_end_only) {
    int end = 10;

    range<int> r = range<int>(end);
    int i = 0;
    range<int>::iterator it = r.begin();
    for (; it != r.end() && i < end; ++it) {
        EXPECT_EQ(i, *it);
        ++i;
    }
}

TEST(int_range_iterator, test_with_start_and_end_only) {
    int start = 3;
    int end = 10;

    range<int> r = range<int>(start, end);
    int i = start;
    range<int>::iterator it = r.begin();
    for (; it != r.end() && i < end; ++it) {
        EXPECT_EQ(i, *it);
        ++i;
    }
}

TEST(int_range_iterator, test_with_start_end_step) {
    int start = 3;
    int end = 10;
    int step = 2;

    range<int> r = range<int>(start, end, step);
    int i = start;
    range<int>::iterator it = r.begin();
    for (; it != r.end() && i < end; ++it) {
        EXPECT_EQ(i, *it);
        i += step;
    }
    EXPECT_EQ(it, r.end());
}