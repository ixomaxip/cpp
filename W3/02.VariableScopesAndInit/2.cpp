#include <iostream>
#include <string>
#include <vector>
using namespace std;


void prt_int()
{
    int x;
    cout << x << endl;
}

void prt_dbl()
{
    double x = 3.14;
    cout << x << endl;
}

int main()
{
    prt_int();
    prt_dbl();
    prt_int();
    /* out:
    21845
    3.14
    1074339512
    */
    return 0;
}