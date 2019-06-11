#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Sum (int x, int y)
{
    return x + y;
}

bool Contains(vector<string> ws, string w)
{
    for (auto s : ws)
    {
        if (s == w)
            return true;
    }
    return false;
}

int main()
{
    int x, y;
    // cin >> x >> y;
    cout << Sum(2,3) << endl;

    cout << Contains({"abc", "def", "asdf"}, "asdf") << endl;
    return 0;
}