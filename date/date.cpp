#include <iostream>
#include "date.hpp"
using std::cout;
using std::endl;
namespace util {

    Date::Order Date::order = Date::Order::MonthDayYear;
    std::string Date::separator = "/";

    Date::Date() {
        time_t t = 0 + (6 * 60 * 60);
        tm breakdown = *localtime(&t);
        _day = breakdown.tm_mday;
        _month = breakdown.tm_mon + 1;
        _year = breakdown.tm_year + 1900;
    }

    Date::Date(int d, int mon, int yr) {
        if(!isValid(d, mon, yr)) {
            throw Invalid{d, mon, yr};
        }
        _day = d;
        _month = mon;
        _year = yr;
    }

    void Date::day(int value) {
        if (!isValid(value, _month, _year)) {
            throw Invalid{value, _month, _year};
        }
         _day = value;
    }

    int Date::day() {
        return _day;
    }  


    void Date::month(int value) {
        if (!isValid(_day, value, _year)) {
            throw Invalid{_day, value, _year};
        }
        _month = value;

    } 

    int Date::month() {
        return _month;
    }


    void Date::year(int value) {
        if (!isValid(_day, _month, value)) {
            throw Invalid{_day, _month, value};
        }
         _year = value;
    }

    int Date::year() {
        return _year;
    }

    void Date::advance(int days){
        if(days != 0) {
            time_t advancedSeconds;
            int seconds = days * 24 * 60 * 60;
            tm t{};
            t.tm_mday = _day;       
            t.tm_mon  = _month - 1;    
            t.tm_year = _year - 1900;  

            time_t currentSeconds = mktime(&t);
            
            advancedSeconds = currentSeconds + seconds;

            tm breakdown = *localtime(&advancedSeconds);
            _day = breakdown.tm_mday;
            _month = breakdown.tm_mon + 1;
            _year = breakdown.tm_year + 1900;
        }
    }


    void Date::print(std::ostream& out) {
        if (order == Order::MonthDayYear) {
            out << _month << separator << _day << separator << _year << "\n";
        }
        else {
            if (order == Order::DayMonthYear) {
                out << _day << separator << _month << separator << _year << "\n";
            }
            else {
                out << _year << separator << _month << separator << _day << "\n";
            }
        }
        
    }

    Date Date::now() {
        time_t t;
        t = time(nullptr);

        tm breakdown = *localtime(&t);
        int currDay = breakdown.tm_mday;
        int currMonth = breakdown.tm_mon + 1;
        int currYear = breakdown.tm_year + 1900;
        Date d(currDay, currMonth, currYear);

        return d;
        
    }


    bool Date::isValid(int d, int m, int y) {
        tm t{};
        t.tm_mday = d;       
        t.tm_mon  = m - 1;    
        t.tm_year = y - 1900;  

        time_t result = mktime(&t);

        if (result == -1) {
            return false;
        }

        if (t.tm_mday != d) return false;
        if (t.tm_mon  != m - 1) return false;
        if (t.tm_year != y - 1900) return false;

        return true;
    }

}
