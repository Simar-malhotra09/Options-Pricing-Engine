#include "Date.h"
#include <iostream>
using namespace std;

int main()
{
    Date d(2008, 3, 17);
    Date e(2008, 5, 11);
    cout << "Size of Date: " << sizeof(Date) << endl;
    d.print();
    e.print();
    if (d < e)
    {
        cout << "d is less than e" << endl;
    }
    else
    {
        cout << "d is not less than e" << endl;
    }

    Date date(2008, 3, 17);
    cout << "Size of Date: " << sizeof(Date) << endl;

    return 0;
}
