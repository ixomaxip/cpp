#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsPalindrom1(string w)
{
    if (w == "")
        return true;

    string tail = w.substr(1);    
    char last = tail.back();

    if (tail == "")
        return true;
    else if (w.front() != last)
        return false;
    else
        return IsPalindrom1(w.substr(1, tail.find(last)));

}

bool IsPalindrom(string w)
{
    for (int i = 0; i < w.size()/2; ++i)
    {
        if (w[i] != w[w.size() - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;

    cout << ((IsPalindrom(s)) ? "true" : "false") << endl;

    return 0;
}