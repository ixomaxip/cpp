#include <iostream>
#include <map>
using namespace std;

void print_map(const map<int, string> & ev)
{
    cout << "size = " << ev.size() << endl;
    for (auto item : ev)
    {
        cout << item.first << ": " << item.second << endl;
    }
}

int main()
{
    map<int, string> events;
    events[1950] = "Bjarne Stroustrup";
    events[1941] = "Dennis Ritchie";
    events[1970] = "UNIX epoch";

    events.erase(1970);
    cout << events[1950] << endl;

    print_map(events);

    return 0;
}