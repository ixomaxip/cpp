#include <iostream>
#include <string>
#include <vector>
using namespace std;


void prt_parity(int x)
{
    string parity = (x % 2 == 0) ? "even" : "odd";    
    cout << x << " is " << parity << endl;
}

void prt_positivity(int x)
{
    string positivity;
    if (x > 0)
    {
        positivity = "positive";
    }
    else if (x < 0)
    {
        positivity = "negative";
    }
    else
    {
        positivity = "zero";
    }
    cout << x << " is " << positivity << endl;
    
}

int main()
{   
    prt_positivity(5);
    prt_positivity(0);
    prt_positivity(-1);
    return 0;
}