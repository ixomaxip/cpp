#include <iostream>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

void prt_date(const Date& dt)
{
    cout << dt.day << "." << dt.month << "." << dt.year << endl;
}


int main()
{
    Date dt = {1,1,2017};
    prt_date(dt);
    return 0;
}