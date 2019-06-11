#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s = "foo";
    {
        string s = "bar";
        cout << s << endl;
    }
    cout << s << endl;
    return 0;
}