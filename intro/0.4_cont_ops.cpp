#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "abcdefg";

    for (char c : s)
    {
        cout << c << "\n";
    }


    cout << '\n';
    return 0;
}