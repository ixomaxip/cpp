#include <iostream>
#include <map>
#include <set>
#include <vector>
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
    // int n, d;
    // char c;
    // is >> n >> c >> d;
    // if (is && c == '/') {
    //      r = Rational(n, d);
    // }
    int num = rat.Numerator();
    int den = rat.Denominator();
    stream >> num;
    stream.ignore(1);
    stream >> den;
    rat = {num, den};
    return stream;
}

bool operator== (const Rational& lhs, const Rational& rhs)
{
    return (lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator());
}

bool operator< (const Rational& lhs, const Rational& rhs)
{
    //return (lhs - rhs).Numerator() < 0;
    if (lhs.Numerator() > 0 && rhs.Numerator() > 0)
    {
        return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
    }
    if (lhs.Numerator() < 0 && rhs.Numerator() < 0)
    {
        return abs(lhs.Numerator()) * rhs.Denominator() > abs(rhs.Numerator()) * lhs.Denominator();
    }
    else
    {
        return lhs.Numerator() < rhs.Numerator();
    }
    
}


int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
