#include <iostream>
#include <vector>
#include <string>
#include "./03.palindrome_selection.h"

using namespace std;

bool IsPalindrom(string w)
{
    for (int i = 0; i < w.size()/2; ++i)
    {
        if (w[i] != w[w.size() - 1 - i])
            return false;
    }
    return true;
}


vector<string> PalindromFilter(vector<string> ws, int minLength)
{
    vector<string> res;

    for (auto w : ws)
    {
        if (IsPalindrom(w) && w.size() >= minLength)
            res.push_back(w);
    }

    return res;
}
