#include <iostream>
#include <string>
#include <vector>
using namespace std;


void prt_parity(int x)
{
    string parity = (x % 2 == 0) ? "even" : "odd";    
    cout << x << " is " << parity << endl;
}

int main()
{   
    prt_parity(5);
    return 0;
}