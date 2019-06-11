#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    ifstream input("input.txt");

    int w = 10;
    int n;    
    int m;
    input >> n >> m;
    
    int val;
    for (int i = 1; i <= n; ++i)
    {
        for (int j =1; j <= m; ++j)
        {
            input >> val;
            input.ignore(1);
            cout << setw(w) << val;
            if (j != m)
                cout << " ";
        }
        cout << endl;
    }   

    return 0;
}