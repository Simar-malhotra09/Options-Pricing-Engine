
#include "Date.h"
#include <cstdlib>
#include<algorithm>
#include<iostream>

Date::Date(int year, int month, int day){
    m_year = year;
    m_month= month;
    m_day = day;
}

Date::Date(const Date& p){
    m_year = p.m_year;
    m_month= p.m_month;
    m_day = p.m_day;
}

Date::~Date(){

}

Date& Date::operator=(const Date &p){

    if (this != &p){
        m_year = p.m_year;
        m_month= p.m_month;
        m_day = p.m_day;
    }
    return *this;
}


// Overloading operators addDay(++), subDay(--), lesserThan(<), isEqual(==);

Date& Date::operator++(){
  

}
Date& Date::operator--(){
  

}

bool Date::operator<(const Date &d) const{

}

bool Date::operator==(const Date &d){

}


bool Date::isTradingDay(){
    if (!isWeekDay()) return false;
    //if (m_holidays.size() == 0) return true;
    if (isHoliday()) return false;
    return true;
} 





