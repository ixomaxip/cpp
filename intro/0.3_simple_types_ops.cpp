#include <iostream>
#include <string>


using namespace std;

int main()
{
    string x = "abc";
    string y = "abc";
    // cout << (x + y) * (x - y);

    if (x < y)
    {
        cout << "less";
    }
    else
        cout << "not less";

    cout << '\n';
    return 0;
}