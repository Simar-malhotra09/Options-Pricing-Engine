#ifndef __CppOptions__Date__
#define __CppOptions__Date__
#include <vector> 

enum DayOfTheWeek {
    DayOfTheWeek_Sunday,
    DayOfTheWeek_Monday,
    DayOfTheWeek_Tuesday,
    DayOfTheWeek_Wednesday,
    DayOfTheWeek_Thursday,
    DayOfTheWeek_Friday,
    DayOfTheWeek_Saturday,
    DayOfTheWeek_UNKNOWN
}; 

enum Month {
    Month_January = 1,
    Month_February,
    Month_March,
    Month_April,
    Month_May,
    Month_June,
    Month_July,
    Month_August,
    Month_September,
    Month_October,
    Month_November,
    Month_December,
 }; 

class Date {
public:
    Date(int year, int month, int day);
    Date(const Date &p);
    ~Date();
    Date &operator=(const Date &p);
    
// setter func
    void setHolidays(const std::vector<Date> &days);
    std::string month();
    std::string dayOfWeek();

// Manipulate dates  
    void add(int numDays);
    void addTradingDays(int numDays);
    void subtract(int numDays);
    void subtractTradingDays(int numDays);

// Helper funcs for dates   
    int dateDifference(const Date &date);
    int tradingDateDifference(const Date &date);
    
    DayOfTheWeek dayOfTheWeek();
    Date nextTradingDay(); 

// Helper funcs for validation
    bool isHoliday();
    bool isWeekDay();
    bool isLeapYear();
    bool isTradingDay();

    void print();
    
    Date &operator++();
    Date &operator--();
    bool operator<(const Date &d) const;
    bool operator==(const Date &d);
    
private:
    int m_year;
    int m_month;
    int m_day;
    DayOfTheWeek m_weekDay;
    std::vector<Date> m_holidays;
};
#endif