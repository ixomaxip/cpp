#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct test
{
    vector<string> in;
    int minLen;
    vector<string> out;
};

vector<string> PalindromFilter(vector<string>, int minLength);

int main()
{
    test t1;
    t1.in = {"abacaba", "aba"};
    t1.minLen = 5;
    t1.out = {"abacaba"};

    test t2;
    t2.in = {"abacaba", "aba"};
    t2.minLen = 2;
    t2.out = {"abacaba", "aba"};

    test t3;
    t3.in = {"weew", "bro", "code"};
    t3.minLen = 4;
    t3.out = {"weew"};

    for (auto t : {t1, t2, t3})
    {
        if (PalindromFilter(t.in, t.minLen) == t.out)
        {
            cout << "OK" << endl;
        }
        else
        {
            cout << "Error" << endl;
        }
    }

    return 0;
}
