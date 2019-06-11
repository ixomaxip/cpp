// C++17!! to try this code got to https://godbolt.org/
#include <map>

using namespace std;

int main()
{
    map<string, int> m = {{"one", 1}, {"two", 2}, {"three", 3}};
    //--std=c++11
    for (const auto & item : m)
    {
        item.first, item.second;
    }
    //--std=c++17
    for (const auto & [k, v] : m)
    {
        k, v;
    }
    return 0;
}