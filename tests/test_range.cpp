#include <gtest/gtest.h>
#include <utils/range.h>

using namespace ul::utils;

#define TVALUE_START 3.0
#define TVALUE_END 248.0
#define TVALUE_STEP 12.3

template <typename T>
class RangeIteratorTest : public testing::Test {
public:
    T start_;
    T end_;
    T step_;
};

using RangeTypes = testing::Types<int, unsigned int, 
                                long, unsigned long, 
                                float, double>;
TYPED_TEST_SUITE(RangeIteratorTest, RangeTypes);

TYPED_TEST(RangeIteratorTest, TestWithEndOnly) {
    this->end_ = (TypeParam)(TVALUE_END);
    range<TypeParam> r = range<TypeParam>(this->end_);
    TypeParam i = 0;
    typename range<TypeParam>::iterator it = r.begin();
    for (; it != r.end() && i < this->end_; ++it) {
        EXPECT_EQ(i, *it);
        ++i;
    }
    EXPECT_EQ(it, r.end());
}

TYPED_TEST(RangeIteratorTest, TestWithStartAndEndOnly) {
    this->start_ = (TypeParam)(TVALUE_START);
    this->end_ = (TypeParam)(TVALUE_END);
    range<TypeParam> r = range<TypeParam>(this->start_, this->end_);
    TypeParam i = this->start_;
    typename range<TypeParam>::iterator it = r.begin();
    for (; it != r.end() && i < this->end_; ++it) {
        EXPECT_EQ(i, *it);
        ++i;
    }
    EXPECT_EQ(it, r.end());
}

TYPED_TEST(RangeIteratorTest, TestWithStartEndStep) {
    this->start_ = (TypeParam)(TVALUE_START);
    this->end_ = (TypeParam)(TVALUE_END);
    this->step_ = (TypeParam)(TVALUE_STEP);
    range<TypeParam> r = range<TypeParam>(this->start_, this->end_, this->step_);
    TypeParam i = this->start_;
    typename range<TypeParam>::iterator it = r.begin();
    for (; it != r.end() && i < this->end_; ++it) {
        EXPECT_EQ(i, *it);
        i += this->step_;
    }
    EXPECT_EQ(it, r.end());
}