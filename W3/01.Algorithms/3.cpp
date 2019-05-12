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
    print(v, "init");
    for (int i = 0; i < v.size(); ++i)
    {
        ++v[i];
    }
    print(v, "inc");
    for (auto& i : v)
    {
        ++i;
    }
    print(v, "double inc");
    

    return 0;
}