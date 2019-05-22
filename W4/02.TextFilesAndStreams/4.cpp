#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    vector<string> names = {"a", "b", "c"};
    vector<double> vels = {5, 0.01, 0.00005};

    for (const auto& n : names)
    {
        cout << n << ' ';
    }
    cout << endl;
    cout << fixed << setprecision(2);
    for (const auto& n : vels)
    {
        cout << n << ' ';
    }
    cout << endl;
    

    return 0;
}