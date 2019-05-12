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

bool gt2(int x)
{
    return x > 2;
}
bool lt2(int x)
{
    return x < 2;
}
int main()
{
    vector<int> v { 1,3,2,5,4,2};
    int cnt = 0;

    cout << count_if(begin(v), end(v), gt2) << endl;
    cout << count_if(begin(v), end(v), lt2) << endl;



    return 0;
}