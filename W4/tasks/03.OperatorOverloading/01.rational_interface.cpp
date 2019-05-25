#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class Rational {
public:
    Rational() : num(0), den(1) {}

    Rational(int numerator, int denominator)
    {        
        if (denominator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }
        int gd = gcd(abs(numerator), abs(denominator));
        num = numerator / gd;
        den = denominator / gd;
    }

    int Numerator() const
    {
        return num;
    }

    int Denominator() const
    {
        return den;
    }

private:
    int num;
    int den;
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        if (b == 0 || b == a)
            return a;
        if (a == 1 || b == 1)
            return 1;
        if (a % 2 == 0 && b % 2 == 0 )
            return 2 * gcd(a /2, b / 2);
        if (a % 2 == 0 && b % 2 != 0)
            return gcd(a / 2, b);
        if (a % 2 != 0 && b % 2 == 0)
            return gcd(a, b / 2);
        if (a % 2 != 0 && b % 2 != 0 && a < b)
            return gcd((b - a) / 2, a);
        if (a % 2 != 0 && b % 2 != 0 && a > b)
            return gcd((a - b) / 2, b);
    }
};

int main() {
    {        
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
