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
};

int main()
{
    return 0;
}