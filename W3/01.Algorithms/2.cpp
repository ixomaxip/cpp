#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void print(const vector<int>& v, const string& title )
{
    cout << title << ": ";
    for (const auto & i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v { 1,3,2,5,4};
    int cnt = 0;
    for (auto i : v)
    {
        if ( i == -2)
            ++cnt;
    }
    cout << cnt << endl;

    return 0;
}