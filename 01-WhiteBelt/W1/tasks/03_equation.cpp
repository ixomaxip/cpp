#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    if (a == 0 && b != 0)
    {
        cout << - c / b  << endl;
    }
    else
    {
        double d = b*b - 4 * a * c;
        if (d > 0)
        {
            cout << 0.5 * (- b + sqrt(d)) / a << " " << 0.5 * (- b - sqrt(d)) / a << endl;
        }
        else if (d == 0 && (a != 0))
        {
            cout << - 0.5 * b / a << endl;
        }
    }

    return 0;
}