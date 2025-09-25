#include <iostream>
#include "gtest/gtest.h"
#include "../date/date.hpp"
#include <sstream>

using namespace util;

TEST(DefaultCtor, CorrectInit) {
    Date d;
    ASSERT_EQ(d.day(), 1);
    ASSERT_EQ(d.month(), 1);
    ASSERT_EQ(d.year(), 1970);
}

TEST(ValueCtor, CorrectInit) {
    Date d1(6, 4, 2005);
    d1 = Date(5, 4, 2005);
    d1 = { 4, 4, 2005 };
    EXPECT_EQ(d1.day(), 4);
    EXPECT_EQ(d1.month(), 4);
    EXPECT_EQ(d1.year(), 2005);
}

TEST(ValueCtor, InvalidDate){
    try {
        Date d2{29, 2, 2001};
    }
    catch(Date::Invalid e) {
        std::ostringstream out;
        out << e.day << "/" << e.month << "/" << e.year << std::endl;
        EXPECT_EQ(out.str(), "29/2/2001\n");
    }
}

TEST(Setters, SetValidDate){
    std::ostringstream stream;
    Date d;
    d.day(25);
    d.month(12);
    d.year(2024);

    d.PrintDate(stream);
    EXPECT_EQ(stream.str(), "25/12/2024\n");
}

TEST(Setters, SetInvalidDate) {
    Date x;
    try {
        x.day(25);
        x.month(13);
    }
    catch(Date::Invalid e) {
        std::ostringstream eout;
        eout << e.day << "/" << e.month << "/" << e.year << std::endl;
        EXPECT_EQ(eout.str(), "25/13/1970\n");
    }
}

TEST(Now, ReturnsCorrectTime) {
    std::ostringstream out;
    Date today = Date::now();
    today.PrintDate(out);
    EXPECT_EQ(out.str(), "25/9/2025\n");
}