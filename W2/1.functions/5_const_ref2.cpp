#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    const string s = "aaaaaaaaaasdf";
    cout << s.size() << endl;
    // s += " bbbb";
    string t = s + "!!!";
    cout << s << endl;
    return 0;
}