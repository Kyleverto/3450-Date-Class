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
        int day();

        void month(int value);
        int month();

        void year(int value);
        int year();

        void advance(int days = 1);
        

        void print(std::ostream& out);


        private:

        int _day;
        int _month;
        int _year;

        bool isValid(int d, int m, int y);

        
    
    };
}