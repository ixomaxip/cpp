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

void print_reverse_map(const map<string, int> & m)
{
    cout << "size = " << m.size() << endl;
    for (auto item : m)
    {
        cout << item.first << ": " << item.second << endl;
    }
}

map<string, int> build_reverse_map(const map<int, string> & ev)
{
    map<string, int> res;
    for (auto i : ev)
    {
        res[i.second] = i.first;
    }
    return res;
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

    print_reverse_map(build_reverse_map(events));

    return 0;
}