#include <iostream>
#include <string>

using namespace std;


/*
На вход дано целое положительное число N. Выведите его в двоичной системе счисления без ведущих нулей.
*/

/*
test:
5	101
32	100000
1	1
*/

int main()
{
    int n;
    cin >> n;
    string rmd = "";
    while (n != 0)
    {
        rmd = ((n%2) ? "1" : "0") + rmd;
        n /= 2;
    }

    cout << rmd << endl;



    return 0;
}