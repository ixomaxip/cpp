#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> t = {8,7,3,4,5};
    int sum = 0;
    for (int x :t)
    {
        sum += x;
    }

    int avg = sum / t.size();

    cout << avg << endl;


    return 0;
}
