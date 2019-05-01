#include <iostream>
#include <string>


using namespace std;

int main()
{
    int x = 3;
    int y = 1;
    // cout << (x + y) * (x - y);

    if ((x - y) * (x + y) > 10)
    {
        cout << "less";
    }
    else
        cout << "not less";

    cout << '\n';
    return 0;
}