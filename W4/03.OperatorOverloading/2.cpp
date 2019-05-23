#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct Duration
{
    int hour;
    int min;

    Duration(int h = 0, int m = 0)
    {
        int total = h * 60 + m;
        hour = total / 60;
        min = total % 60;
    }
};

ostream& operator<<(ostream& stream, const Duration& dur)
{
    stream << setfill('0');
    stream << setw(2) << dur.hour << ':'
           << setw(2) << dur.min;
    return stream;
}

istream& operator>>(istream& stream, Duration& dur)
{
    stream >> dur.hour;
    stream.ignore(1);
    stream >> dur.min;
    return stream;
}

Duration operator+(const Duration& lhs, const Duration& rhs)
{
    return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

int main()
{
    stringstream dur_ss("03:50");
    Duration d1;
    Duration d2 = {0, 35};
    dur_ss >> d1;
    cout << d1 + d2 << endl;
    return 0;
}