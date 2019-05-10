#include <iostream>
#include <map>
using namespace std;

void print_map(const map<string, int> & ev)
{
    for (const auto& item : ev)
    {
        cout << item.first << ": " << item.second << endl;
    }
}
int main()
{
    map <string, int> m = {{"one", 1}, {"two", 2}, {"three", 3}};

    print_map(m);
    return 0;
}