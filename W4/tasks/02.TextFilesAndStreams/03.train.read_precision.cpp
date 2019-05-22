#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    ifstream input("input.txt");
    if (input)
    {
        double val;
        cout << fixed << setprecision(3);
        while (input >> val)
        {
            cout << val << endl;
        }
    }        
    return 0;
}