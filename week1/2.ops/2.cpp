#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int a = 11;
    int b =3;

    cout << a / b << endl
    << double (a) / b << endl
    << a / double(b) << endl;

    int x = 5;
    x = x + 2;
    cout << x << endl;

    return 0;
}