#include <iostream>
#include <vector>
#include <string>
using namespace std;

void swap(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    int a = 1;
    int b = 2;
    swap(a,b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;


    return 0;
}