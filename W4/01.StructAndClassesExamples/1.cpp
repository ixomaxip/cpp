#include <iostream>

using namespace std;

struct Day
{
    int value;
    explicit Day(int new_val)
    {
        value = new_val;
    }
};
struct Month
{
    int value;
    explicit Month(int new_val)
    {
        value = new_val;
    }
};
struct Year
{
    int value;
    explicit Year(int new_val)
    {
        value = new_val;
    }
};

struct Date
{
    int day;
    int month;
    int year;

    Date(Day new_day, Month new_month, Year new_year)
    {
        day = new_day.value;
        month = new_month.value;
        year = new_year.value;
    }
};

void prt_date(const Date& dt)
{
    cout << dt.day << "." << dt.month << "." << dt.year << endl;
}


int main()
{
    Date dt = {Day{10}, Month{11}, Year{12}};
    prt_date(dt);
    return 0;
}