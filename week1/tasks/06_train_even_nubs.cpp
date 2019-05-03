#include <iostream>

using namespace std;

/*
tests
1 10    ->  2 4 6 8 10
2 3     -> 	2
9 11    ->  10
*/

int main()
{
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        if (i % 2 == 0)
        {
            cout << i << ' ';
        }
    }
    cout << endl;

    return 0;
}