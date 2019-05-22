#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


void prt(const vector<string> nms, const vector<double> vals, int w)
{  
    cout << setfill('.');
    cout << left;
    for (const auto& n : nms)
    {
        cout << setw(w) << n << ' ';
    }
    cout << endl;
    cout << fixed << setprecision(2);
    for (const auto& n : vals)
    {
        cout << setw(w);
        cout << n << ' ';
    }
    cout << endl;
}

int main()
{
    vector<string> names = {"a", "b", "c"};
    vector<double> vals = {5, 0.01, 0.00005};   
    prt(names, vals, 5);

    return 0;
}