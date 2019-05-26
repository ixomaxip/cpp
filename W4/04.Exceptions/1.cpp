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

void ensure_next_symbol_and_skip(stringstream& stream)
{
    if (stream.peek() != '/')
    {
        throw exception();
    }
    stream.ignore(1);
}

Date parse_date(const string& s)
{
    stringstream stream(s);
    Date dt;
    stream >> dt.year;
    
    ensure_next_symbol_and_skip(stream);

    stream >> dt.month;

    ensure_next_symbol_and_skip(stream);
    
    stream >> dt.day;
    stream.ignore(1);
    return dt;
}

int main()
{

    string date_str = "2017a01b25";

    try
    {
        Date dt = parse_date(date_str);
        cout << setw(2) << setfill('0') << dt.day << "."
             << setw(2) << setfill('0') << dt.month << "."
             << setw(2) << setfill('0') << dt.year << endl;
    }
    catch(const std::exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
