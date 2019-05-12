#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    string s1 = "abc", s2 = "bca";
    cout << min(s1,s2) << endl;
    cout << max(s1,s2) << endl;

    return 0;
}