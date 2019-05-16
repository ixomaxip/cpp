#include <iostream>

using namespace std;

class A
{
    public:
        void changeA(int x, const string& newA)
        {}
        void changeA2(int x, const string& newA2)
        {}
        string get_A(int x)
        {}
};

int main()
{
    A a;
    a.changeA(1, "B");
    a.changeA2(2, "С");
    for (int x : {0, 2, 4})
    {
        cout << a.get_A(x);
    }

    a.changeA(4, "D");
    for (int x : {1, 4})
    {
        cout << a.get_A(x);
    }
    cout << endl;
}