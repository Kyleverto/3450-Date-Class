#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <ctime>
#include <string>

namespace util {
    class Date {
        public:
        struct Invalid {
            int day;
            int month;
            int year;
        };
        enum class Order {
            MonthDayYear,
            DayMonthYear,
            YearMonthDay
        };  

        static Order order;
        static std::string separator;

        Date();
        Date(int d, int mon, int yr);
        static Date now();


        void day(int value);
        int day() const;

        void month(int value);
        int month() const;

        void year(int value);
        int year() const;

        void advance(int days = 1);
        
        std::string monthName() const;
        std::string dayName() const;

        void print(std::ostream& out) const;



        private:

        int _day;
        int _month;
        int _year;

        bool isValid(int d, int m, int y);

        
    
    };
}