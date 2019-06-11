#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

/*
stdin	    stdout
2 q A	    A q
3 a C b	    a b C
*/

string s_tolower(string s)
{
    for (auto& c : s)
    {
        c = tolower(c);
    }
    return s;
}

int main()
{
    int N;
    cin >> N;
    vector<string> v(N);

    for (auto& i : v) {cin >> i;}

    sort(begin(v), end(v), [](const string& s1, const string& s2)
    {
        return s_tolower(s1) < s_tolower(s2);
    });

    // sort(begin(v), end(v),
    //     [](const string& l, const string& r)
    //     {
    //         return lexicographical_compare(begin(l), end(l), begin(r), end(r),
    //             [](char cl, char cr) { return tolower(cl) < tolower(cr); });
    //     }
    // );

    for (const auto& i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}