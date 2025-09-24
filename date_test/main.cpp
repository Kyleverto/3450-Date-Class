#include <iostream>
#include "gtest/gtest.h"
#include "../date/date.hpp"
#include <sstream>

using namespace util;

TEST(DefaultCtor, CorrectInit) {
    Date d;
    ASSERT_EQ(d.day, 1);
    ASSERT_EQ(d.month, 1);
    ASSERT_EQ(d.year, 1970);
}
