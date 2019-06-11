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
    cout << (-1 < 1u) << endl;

    return 0;
}
