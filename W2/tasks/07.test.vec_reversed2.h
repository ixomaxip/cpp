#include <iostream>
#include <vector>
#include <string>
// #include "./06.test.vec_reverse.h"
using namespace std;

vector<int> Reversed(const vector<int>& v);

struct test
{
    vector<int> in;
    vector<int> out;
};

int main()
{
    vector<test> tests = 
    {
        {{1,2,3,4,5}, {5,4,3,2,1}},
        {{1}, {1}},
        {{1,1}, {1,1}},
        {{4,2,3,4,1}, {1,4,3,2,4}},
        {{4,2,3,4}, {4,3,2,4}},

    };
    for (auto t : tests)
    {
        auto out = Reversed(t.in);

        cout << ((out == t.out) ? "Ok" : "Error") << endl;
    }
    return 0;
}