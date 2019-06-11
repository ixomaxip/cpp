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
    vector<int> v { 1,3,2,5,4,2};
    int cnt = 0;
    int thr;
    cin >> thr;

    cout << count_if(begin(v), end(v), [thr](int x ) {return x > thr;}) << endl;
    

    return 0;
}