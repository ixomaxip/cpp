#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input("date.txt");
    
    int year = 0, month = 0, day = 0;
    if (input)
    {
        input >> year;
        input.ignore(1);
        input >> month;
        input.ignore(1);
        input >> day;
    }
    cout << year << " " << month << " " << day << endl;
    
    return 0;
}