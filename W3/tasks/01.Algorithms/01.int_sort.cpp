#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

/*
stdin	    stdout
2 -4 3	    3 -4
3 1 -3 2    1 2 -3
*/


int main()
{
    int N;
    cin >> N;
    vector<int> v(N);

    for (auto& i : v) {cin >> i;}
    sort(begin(v), end(v), []( int& a,  int& b)
        {
            return abs(a) < abs(b);
        });
    for (const auto& i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}