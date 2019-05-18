#include <iostream>

using namespace std;

class A
{
    public:
        void changeA(const string& newA, int x)
        {}
        void changeA2(const string& newA2, int x)
        {}
        string get_A(int x)
        {}
        int AA;
};

int main()
{
    A a;
    a.changeA("Basdfasdf", 1);
    a.changeA2("С", 2);
    for (int x : {0, 2, 4})
    {
        cout << a.get_A(x);
    }

    a.changeA("D", 3);
    for (int x : {1, 4})
    {
        cout << a.get_A(x);
    }
    cout << endl;
}