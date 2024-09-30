#include <gtest/gtest.h>
#include <utils/range2d.h>
#include <iostream>

using namespace ul::utils;

#define XVALUE_START 3.0
#define XVALUE_END 248.0
#define XVALUE_STEP 12.3

#define YVALUE_START 3.0
#define YVALUE_END 248.0
#define YVALUE_STEP 12.3

template <typename T>
class Range2DIteratorTest : public testing::Test {
public:
    T start_x; T start_y;
    T end_x; T end_y;
    T step_x; T step_y;
};

using Range2DTypes = testing::Types<int, unsigned int, 
                                long, unsigned long, 
                                float, double>;
TYPED_TEST_SUITE(Range2DIteratorTest, Range2DTypes);

TYPED_TEST(Range2DIteratorTest, TestWithEndOnly) {
    this->end_x = (TypeParam)(XVALUE_END);
    this->end_y = (TypeParam)(YVALUE_END);
    using r1dIter = typename range<TypeParam>::iterator;
    range<TypeParam> rX(this->end_x);
    range<TypeParam> rY(this->end_y);
    range2d<TypeParam> r(rX, rY);
    typename range2d<TypeParam>::iterator rit = r.begin();
    for (r1dIter j = rY.begin(); j != rY.end(); ++j)
    {
        for (r1dIter i = rX.begin(); i != rX.end(); ++i)
        {
            EXPECT_EQ(rit->first, *i);
            EXPECT_EQ(rit->second, *j);
            ++rit;
        }
    }
    EXPECT_EQ(rit, r.end());
}

TYPED_TEST(Range2DIteratorTest, TestWithStartAndEndOnly) {
    this->start_x = (TypeParam)(XVALUE_START);
    this->start_y = (TypeParam)(YVALUE_START);
    this->end_x = (TypeParam)(XVALUE_END);
    this->end_y = (TypeParam)(YVALUE_END);
    using r1dIter = typename range<TypeParam>::iterator;
    range<TypeParam> rX(this->start_x, this->end_x);
    range<TypeParam> rY(this->start_y, this->end_y);
    range2d<TypeParam> r(rX, rY);
    typename range2d<TypeParam>::iterator rit = r.begin();
    for (r1dIter j = rY.begin(); j != rY.end(); ++j)
    {
        for (r1dIter i = rX.begin(); i != rX.end(); ++i)
        {
            EXPECT_EQ(rit->first, *i);
            EXPECT_EQ(rit->second, *j);
            ++rit;
        }
    }
    EXPECT_EQ(rit, r.end());
}

TYPED_TEST(Range2DIteratorTest, TestWithStartEndStep) {
    this->start_x = (TypeParam)(XVALUE_START);
    this->start_y = (TypeParam)(YVALUE_START);
    this->end_x = (TypeParam)(XVALUE_END);
    this->end_y = (TypeParam)(YVALUE_END);
    this->step_x = (TypeParam)(XVALUE_STEP);
    this->step_y = (TypeParam)(YVALUE_STEP);
    using r1dIter = typename range<TypeParam>::iterator;
    range<TypeParam> rX(this->start_x, this->end_x, this->step_x);
    range<TypeParam> rY(this->start_y, this->end_y, this->step_y);
    range2d<TypeParam> r(rX, rY);
    typename range2d<TypeParam>::iterator rit = r.begin();
    for (r1dIter j = rY.begin(); j != rY.end(); ++j)
    {
        for (r1dIter i = rX.begin(); i != rX.end(); ++i)
        {
            EXPECT_EQ(rit->first, *i);
            EXPECT_EQ(rit->second, *j);
            ++rit;
        }
    }
    EXPECT_EQ(rit, r.end());
}