#ifndef __CppOptions__Date__
#define __CppOptions__Date__

class Date {
public:
    Date(int year, int month, int day);
    Date(const Date &p);
    ~Date();
    Date &operator=(const Date&p);
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    int year();
    int month();
    int day();
    void print();
    bool operator==(const Date &d) const;
    bool operator<(const Date &d) const;
    
private:
    char m_date[8];
};

#endif 
