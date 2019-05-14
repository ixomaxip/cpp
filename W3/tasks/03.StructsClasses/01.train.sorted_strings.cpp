#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s)
    {
        _strings.push_back(s);
    }
    vector<string> GetSortedStrings()
    {
        sort(begin(_strings), end(_strings));
        return _strings;
    }
private:
    vector<string> _strings;
};