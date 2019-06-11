#include <iostream>
#include <vector>
#include <string>
using namespace std;

void PrintWords(vector<string> ws)
{
    for (auto w : ws)
    {
        cout << w << " " << endl;
    }
}

void change_int(int x)
{
    x = 42;
}

int main()
{

    PrintWords({"asdf", "Qwer"});

    int a = 5;
    change_int(a);
    cout << a << endl;

    return 0;
}