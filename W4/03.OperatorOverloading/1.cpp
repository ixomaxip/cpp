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
};

Duration read_duration(istream& stream)
{
    int h = 0;
    int m = 0;
    stream >> h;
    stream.ignore(1);
    stream >> m;

    return Duration {h, m};
}

ostream& operator<<(ostream& stream, const Duration& dur)
{
    stream << setfill('0');
    stream << setw(2) << dur.hour << ':'
           << setw(2) << dur.min;
    return stream;
}

int main()
{
    stringstream dur_ss("01:50");
    Duration d1 = read_duration(dur_ss);
    cout << d1 << endl;
    return 0;
}