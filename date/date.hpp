#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <ctime>

namespace util {
    class Date {
        public:
        struct Invalid {
            int day;
            int month;
            int year;
        };

        int day;
        int month;
        int year;

        Date();
        Date(int d, int mon, int yr);
        static Date now();

        void PrintDate(std::ostream& out);


        private:

        bool isValid(int d, int m, int y);
        
        enum class Order {
            MonthDayYear,
            DayMonthYear,
            YearMonthDay
        };    
    };
}