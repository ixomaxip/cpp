#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int x = 5;
    x =6;

    cout << x << endl;

    string s = "foo";
    string t = s;

    t += " bar";

    cout << "s = " << s << endl;
    cout << "t = " << t << endl;


    cout << endl;
    return 0;
}