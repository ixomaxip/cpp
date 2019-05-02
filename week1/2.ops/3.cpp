#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    map<string, int> a;
    a["one"] = 1;
    map<string, int> b;

    if (a == b)
    {
        cout << "a is equal b" << endl;
    }
    else
    {
        cout << "a is not equal b" << endl;
    }
    
    string s = "abc";
    if (!s.empty() && s < "zzz")
        cout << s << endl;

    

    return 0;
}