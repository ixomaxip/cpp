#include <iostream>
#include <vector>
#include <limits>


using namespace std;

int main()
{
    cout << sizeof(int) << endl;
    cout << numeric_limits<int>::min() << " ";
    cout << numeric_limits<int>::max() << endl;
    cout << "long int size: " << sizeof(long int) << endl;
    cout << numeric_limits<long int>::max() << endl;



    return 0;
}
