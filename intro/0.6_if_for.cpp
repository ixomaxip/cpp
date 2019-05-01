#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
    int x = 4;
    int y =5;

    if (x == y)
        cout << "equal";

    int n = 5;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += i;
    }
    cout << "sum = " << sum << '\n';
    
    sum = 0;
    int i = 1;
    while (i<= n)
    {
        sum += i;
        i++;
    }
    cout << "while sum = " << sum << '\n';

    return 0;
}