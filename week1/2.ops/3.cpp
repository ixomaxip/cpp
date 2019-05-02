#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> a = {"fire", "water"};
    vector<string> b = {"fog", "air"};

    if (a == b)
    {
        cout << "a is equal b" << endl;
    }
    else
    {
        cout << "a is not equal b" << endl;
    }
    

    

    return 0;
}