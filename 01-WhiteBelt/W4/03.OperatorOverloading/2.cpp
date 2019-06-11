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

bool operator<(const Duration& lhs, const Duration& rhs)
{
    if (lhs.hour == rhs.hour)
    {
        return lhs.min < rhs.min;
    }
    else
    {
        return lhs.hour < rhs.hour;
    }
    
}

void print_vector(const vector<Duration>& v)
{
    for (const auto& d : v)
    {
        cout << d << " ";
    }

    cout << endl;
}

int main()
{
    stringstream dur_ss("03:50");
    Duration d1;
    dur_ss >> d1;

    Duration d2 = {0, 35};
    Duration d3 = d1 + d2;

    vector<Duration> v {d3, d2, d1};
    print_vector(v);
    sort(v.begin(), v.end());
    print_vector(v);
    return 0;
}