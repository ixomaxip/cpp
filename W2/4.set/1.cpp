#include <iostream>
#include <set>
#include <map>
using namespace std;

void print_set(const set<string>& s)
{
    cout << "Size = " << s.size() << endl;
    for (auto x : s)
    {
        cout << x << endl;
    }
}

int main()
{
    set<string> is_fam;
    is_fam.insert("Stroustrup");
    is_fam.insert("Stroustrup");
    is_fam.insert("Ritchie");
    is_fam.insert("Bla");

    print_set(is_fam);
    cout << endl;
    is_fam.erase("Bla");
    print_set(is_fam);

    return 0;
}