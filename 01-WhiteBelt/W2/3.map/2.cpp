#include <iostream>
#include <map>
#include <vector>
using namespace std;

void print_map(const map<string, int> & ev)
{
    cout << "size = " << ev.size() << endl;
    for (const auto& item : ev)
    {
        cout << item.first << ": " << item.second << endl;
    }
}
int main()
{
    // map <string, int> m = {{"one", 1}, {"two", 2}, {"three", 3}};

    // print_map(m);
    // m.erase("three");
    // print_map(m);

    // vector<string> words = {"one", "two", "one"};
    // map<string, int> cnt;
    // for (const auto & w : words)
    // {
    //     print_map(cnt);
    //     ++cnt[w];
    // }

    // print_map(cnt);

    vector<string> words = {"one", "two", "three"};
    map<char, vector<string>> grouped;
    for (const auto & w: words)
    {
        grouped[w[0]].push_back(w);
    }
    for (const  auto & c : grouped)
    {
        cout << c.first << endl;
        for (const string & w : c.second)
        {
            cout << w << " ";
        }
        cout << endl;
    }


    return 0;
}