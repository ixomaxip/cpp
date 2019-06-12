#include <iostream>
#include <vector>
#include <limits>


using namespace std;


void prt_avg()
{
    vector<int> t = {-8, -7, 3};
    
    int sum = 0;
    for (int x : t)
    {
        sum += x;
    }
    int avg = sum / t.size();
    cout << avg << endl;
}

int main()
{
    vector<int> x = {4,5};
    for (size_t i = 0; i < x.size(); ++i)
    {
        cout << i << " " << x[i] << endl;
    }
    // or static cats
    for (int i = 0; i < static_cast<int>(x.size()); ++i)
    {
        cout << i << " " << x[i] << endl;
    }

    return 0;
}
