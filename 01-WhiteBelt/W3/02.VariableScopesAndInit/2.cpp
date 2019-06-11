#include <iostream>
#include <string>
#include <vector>
using namespace std;


void prt_parity(int x)
{
    string parity = (x % 2 == 0) ? "even" : "odd";    
    cout << x << " is " << parity << endl;
}

string get_positivity(int x)
{
    if (x > 0)
    {
        return "positive";
    }
    else if (x < 0)
    {
        return "negative";
    }
    else
    {
        return "zero";
    }

}

void prt_positivity(int x)
{
    string positivity = get_positivity(x);
    cout << x << " is " << positivity << endl;
    
}

int main()
{   
    prt_positivity(5);
    prt_positivity(0);
    prt_positivity(-1);
    return 0;
}