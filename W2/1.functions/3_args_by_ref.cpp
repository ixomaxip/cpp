#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void swap(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

vector<int> mysort(vector<int> v)
{
    sort(begin(v), end(v));
    return v;
}

int main()
{
    vector<int> ns = {3,6,2,3,5,6,4};
    ns = mysort(ns);
    for (auto n : ns)
    {
        cout << n << ' ';
    }

    cout << endl;
    return 0;
}