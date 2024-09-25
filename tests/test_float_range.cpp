#include <gtest/gtest.h>
#include <utils/range.h>

using namespace ul::utils;

TEST(float_range_iterator, test_with_end_only) {
    float end = 20.0;

    range<float> r = range<float>(end);
    float i = 0;
    range<float>::iterator it = r.begin();
    for (; it != r.end() && i < end; ++it) {
        EXPECT_EQ(i, *it);
        ++i;
    }
}

TEST(float_range_iterator, test_with_start_and_end_only) {
    float start = 5.0;
    float end = 20.0;

    range<float> r = range<float>(start, end);
    float i = start;
    range<float>::iterator it = r.begin();
    for (; it != r.end() && i < end; ++it) {
        EXPECT_EQ(i, *it);
        ++i;
    }
}

TEST(float_range_iterator, test_with_start_end_step) {
    float start = 5.0;
    float end = 20.0;
    float step = 3.2;

    range<float> r = range<float>(start, end, step);
    float i = start;
    range<float>::iterator it = r.begin();
    for (; it != r.end() && i < end; ++it) {
        EXPECT_EQ(i, *it);
        i += step;
    }
    EXPECT_EQ(it, r.end());
}