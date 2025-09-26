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
        out << e.month << "/" << e.day << "/" << e.year << std::endl;
        EXPECT_EQ(out.str(), "2/29/2001\n");
    }
}

TEST(print, CorrectFormat){
    std::ostringstream out;
    Date d{25, 12, 2024};
    d.print(out);
    EXPECT_EQ(out.str(), "12/25/2024\n");

    Date::order = Date::Order::DayMonthYear;
    Date::separator = "-";
    out.str("");
    d.print(out);
    EXPECT_EQ(out.str(), "25-12-2024\n");

    Date::order = Date::Order::YearMonthDay;
    Date::separator = ".";
    out.str("");
    d.print(out);
    EXPECT_EQ(out.str(), "2024.12.25\n");

    Date::order = Date::Order::MonthDayYear;
    Date::separator = "/";

}

TEST(Setters, SetValidDate){
    std::ostringstream out;
    Date d;
    d.day(25);
    d.month(12);
    d.year(2024);

    d.print(out);
    EXPECT_EQ(out.str(), "12/25/2024\n");
}

TEST(Setters, SetInvalidDate) {
    Date x;
        std::ostringstream out;
    try {
        x.day(25);
        x.month(13);
    }
    catch(Date::Invalid e) {
        out << e.month << "/" << e.day << "/" << e.year << std::endl;
        EXPECT_EQ(out.str(), "13/25/1970\n");
    }

    out.str("");
    
    try {
        x.day(29);
        x.month(2);
    }
    catch(Date::Invalid e) {
        out << e.month << "/" << e.day << "/" << e.year << std::endl;
        EXPECT_EQ(out.str(), "2/29/1970\n");
    }
}

TEST(Now, ReturnsCorrectTime) {
    std::ostringstream out;
    Date today = Date::now();
    today.print(out);
    EXPECT_EQ(out.str(), "9/25/2025\n");
}

TEST(advance, MovesForward) {
    std::ostringstream out;
    Date d{6, 4, 2005};

    d.advance();
    d.print(out);
    EXPECT_EQ(out.str(), "4/7/2005\n");

    out.str("");

    d.advance(389);
    d.print(out);
    EXPECT_EQ(out.str(), "5/1/2006\n");
}

TEST(advance, MovesBackwards){
    std::ostringstream out;
    Date d{6, 4, 2005};

    d.advance(-5);
    d.print(out);
    EXPECT_EQ(out.str(), "4/1/2005\n");

    out.str("");

    d.advance(-366);
    d.print(out);
    EXPECT_EQ(out.str(), "3/31/2004\n");
}