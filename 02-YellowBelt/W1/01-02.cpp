#include <iostream>
#include <vector>
#include <limits>


using namespace std;

int main()
{
    cout << numeric_limits<int>::max() + 1 << " "
        << numeric_limits<int>::min() - 1 << endl;



    return 0;
}
