#include <iostream>
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

bool operator== (const Rational& lhs, const Rational& rhs)
{
    return (lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator());
}

Rational operator+ (const Rational& lhs, const Rational& rhs)
{
    Rational result {lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
                     lhs.Denominator() * rhs.Denominator()};
    return result;
}

Rational operator- (const Rational& lhs, const Rational& rhs)
{
    Rational result {lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
                     lhs.Denominator() * rhs.Denominator()};
    return result;
}

Rational operator* (const Rational& lhs, const Rational& rhs)
{
    Rational result {lhs.Numerator() * rhs.Numerator(),
                     lhs.Denominator() * rhs.Denominator()};
    return result;
}
Rational operator/ (const Rational& lhs, const Rational& rhs)
{
    Rational result {lhs.Numerator() * rhs.Denominator(),
                     lhs.Denominator() * rhs.Numerator()};
    return result;
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
