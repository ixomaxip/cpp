#include <iostream>
#include <map>
#include <set>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string> & m);

int main()
{
    map<int, string> t1 {
                            {1, "odd"},
                            {2, "even"},
                            {3, "odd"},
                            {4, "even"},
                            {5, "odd"}
                        };
    set<string> values = BuildMapValuesSet(t1);
    if (values == set<string>{"odd", "even"})
    {
        cout << "Ok" << endl;
    } else {
        cout << "Error" << endl;
    }
}