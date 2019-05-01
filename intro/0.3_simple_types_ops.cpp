#include <iostream>
#include <string>


using namespace std;

int main()
{
    int x = 4;
    int y = 5;
    cout << (x + y) * (x - y);

    if (x == y)
    {
        cout << "equal";
    }
    else
        cout << "not equal";

    cout << '\n';
    return 0;
}