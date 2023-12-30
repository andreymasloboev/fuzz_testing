#include "fuzztest/fuzztest.h"
#include "gtest/gtest.h"

#include "resource.hpp"

TEST(ResourceTS, SetStatus)
{
    Resource resource;

    constexpr int VALID_STATUS = 5;
    ASSERT_TRUE(resource.setStatus(VALID_STATUS));

    constexpr int INVALID_STATUS = -5;
    ASSERT_FALSE(resource.setStatus(INVALID_STATUS));
}

void SetStatusAlwaysSucceedPositiveIntegers(int status)
{
    Resource resource;
    ASSERT_TRUE(resource.setStatus(status));
}

FUZZ_TEST(ResourceTS, SetStatusAlwaysSucceedPositiveIntegers)
    .WithDomains(/*status:*/ fuzztest::Positive<int>());

void SetStatusAlwaysFailNegativeIntegers(int status)
{
    Resource resource;
    ASSERT_FALSE(resource.setStatus(status));
}

FUZZ_TEST(ResourceTS, SetStatusAlwaysFailNegativeIntegers)
    .WithDomains(/*status:*/ fuzztest::Negative<int>());