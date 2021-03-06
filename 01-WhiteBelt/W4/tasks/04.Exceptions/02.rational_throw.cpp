#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class Rational {
public:
    Rational() : num(0), den(1) {}

    Rational(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            throw invalid_argument("invalid_argument");
        }
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
    if (rhs.Numerator() == 0)
    {
        throw domain_error("domain_error");
    }
    Rational result {lhs.Numerator() * rhs.Denominator(),
                     lhs.Denominator() * rhs.Numerator()};
    return result;
}

ostream& operator<<(ostream& stream, const Rational& rat)
{
    stream << rat.Numerator() << "/" << rat.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rat)
{
    int n, d;
    char c;
    stream >> n >> c >> d;
    if (stream && c == '/')
    {
         rat = Rational(n, d);
    }
    return stream;
}

bool operator== (const Rational& lhs, const Rational& rhs)
{
    return (lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator());
}

bool operator< (const Rational& lhs, const Rational& rhs)
{
    return (lhs - rhs).Numerator() < 0;
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}