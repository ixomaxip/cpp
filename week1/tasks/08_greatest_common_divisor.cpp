#include <iostream>
#include <string>

using namespace std;


/*
В stdin даны два натуральных числа. Выведите в stdout их наибольший общий делитель.
*/

/*
test:
25 27	1
12 16	4
13 13	13
*/

int main()
{
    int a, b;
    cin >> a >> b;

    while (a > 0 and b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }

    cout << a + b << endl;

    return 0;
}