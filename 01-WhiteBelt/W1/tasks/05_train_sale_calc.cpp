#include <iostream>

using namespace std;

/*
tests
100 110 120 5 10 -> 100
115 110 120 5 10 -> 109.25
150 110 120 5 12.5 -> 131.25
*/

int main()
{
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;

    double discount = 0;

    if (n > b)
    {
        discount =  n * y / 100.0;
    }
    else if (n > a)
    {
        discount =  n * x / 100.0;       
    }

    cout << n - discount << endl;

    return 0;
}