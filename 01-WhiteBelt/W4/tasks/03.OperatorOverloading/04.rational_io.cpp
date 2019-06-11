#include <iostream>
#include <sstream>
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

ostream& operator<<(ostream& stream, const Rational& rat)
{
    stream << rat.Numerator() << "/" << rat.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rat)
{
    int num = rat.Numerator();
    int den = rat.Denominator();
    stream >> num;
    stream.ignore(1);
    stream >> den;
    rat = {num, den};
    return stream;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
