#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
/*
input:
6
first
second
first
third
second
second

output:
3
*/

int main()
{
    int n;
    cin >> n;
    set<string> strings;
    while (n-- > 0)
    {
        string s;
        cin >> s;
        strings.insert(s);
    }
    cout << strings.size() << endl;
    return 0;
}