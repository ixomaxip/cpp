#include <iostream>
#include <vector>
#include <limits>


using namespace std;

int main()
{
    vector<int> v;// = {1,4,6,4};

    for (size_t i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}
