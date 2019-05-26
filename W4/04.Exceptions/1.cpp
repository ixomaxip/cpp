#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <exception>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

Date parse_date(const string& s)
{
    stringstream stream(s);
    Date dt;
    stream >> dt.year;
    stream.ignore(1);
    stream >> dt.month;
    stream.ignore(1);
    stream >> dt.day;
    stream.ignore(1);
    return dt;
}

int main()
{
    string date_str = "2017/01/25";
    Date dt = parse_date(date_str);
    cout ;
    cout    << setw(2) << setfill('0') << dt.day << "."
            << setw(2) << setfill('0') << dt.month << "."
            << setw(2) << setfill('0') << dt.year << endl;
    return 0;
}
