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
    int avg = sum / static_cast<int>(t.size());
    cout << avg << endl;
}

int main()
{
    prt_avg();
    return 0;
}
