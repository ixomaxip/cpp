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

    set<string> months = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
    set<string> months2 = {"JUN", "JUL", "AUG", "SEP", "OCT", "JAN", "FEB", "MAR", "APR", "MAY", "NOV", "DEC"};
    print_set(months);
    cout << (months == months2) << endl;

    return 0;
}