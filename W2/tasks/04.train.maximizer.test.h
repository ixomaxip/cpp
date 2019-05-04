#include <iostream>
#include <string>
#include <vector>
using namespace std;

void UpdateIfGreater(const int& first, int& second);

int main()
{
    vector<vector<int>> tests = 
    {
        {4, 2, 4},
        {2, 4, 4},
        {0, 0, 0}
    };
    
    for (auto t : tests)
    {
        UpdateIfGreater(t[0], t[1]);

        if (t[1] == t[2])
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
