#include "Date.h"
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

Date::Date(int year, int month, int day)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

Date::Date(const Date &p)
{
    strcpy(m_date, p.m_date);
}

Date::~Date()
{
}

Date &Date::operator=(const Date &p)
{
    if (&p != this)
    {
        strcpy(m_date, p.m_date);
    }
    return *this;
}

bool Date::operator==(const Date &d) const
{
    return strncmp(m_date, d.m_date, 8) == 0;
}

bool Date::operator<(const Date &d) const
{
    return strncmp(m_date, d.m_date, 8) < 0;
}

int Date::year()
{
    return 1000 * (m_date[0] - '0') + 100 * (m_date[1] - '0') + 10 * (m_date[2] - '0') + (m_date[3] - '0');
}

int Date::month()
{
    return 10 * (m_date[4] - '0') + (m_date[5] - '0');
}

int Date::day()
{
    return 10 * (m_date[6] - '0') + (m_date[7] - '0');
}

void Date::print()
{
    char s[9];
    strncpy(s, m_date, 8);
    s[8] = '\0';
    cout << s << endl;
}

void Date::setYear(int year)
{
    m_date[3] = '0' + (year % 10);
    year /= 10;
    m_date[2] = '0' + (year % 10);
    year /= 10;
    m_date[1] = '0' + (year % 10);
    year /= 10;
    m_date[0] = '0' + (year % 10);
}

void Date::setMonth(int month)
{
    m_date[5] = '0' + (month % 10);
    month /= 10;
    m_date[4] = '0' + (month % 10);
    month /= 10;
}

void Date::setDay(int day)
{
    m_date[7] = '0' + (day % 10);
    day /= 10;
    m_date[6] = '0' + (day % 10);
    day /= 10;
}

