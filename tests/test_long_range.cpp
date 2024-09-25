#include <gtest/gtest.h>
#include <utils/range.h>

using namespace ul::utils;

TEST(long_range_iterator, test_with_end_only) {
    long end = 200;

    range<long> r = range<long>(end);
    long i = 0;
    range<long>::iterator it = r.begin();
    for (; it != r.end() && i < end; ++it) {
        EXPECT_EQ(i, *it);
        ++i;
    }
}

TEST(long_range_iterator, test_with_start_and_end_only) {
    long start = 50;
    long end = 200;

    range<long> r = range<long>(start, end);
    long i = start;
    range<long>::iterator it = r.begin();
    for (; it != r.end() && i < end; ++it) {
        EXPECT_EQ(i, *it);
        ++i;
    }
}

TEST(long_range_iterator, test_with_start_end_step) {
    long start = 50;
    long end = 200;
    long step = 10;

    range<long> r = range<long>(start, end, step);
    long i = start;
    range<long>::iterator it = r.begin();
    for (; it != r.end() && i < end; ++it) {
        EXPECT_EQ(i, *it);
        i += step;
    }
    EXPECT_EQ(it, r.end());
}