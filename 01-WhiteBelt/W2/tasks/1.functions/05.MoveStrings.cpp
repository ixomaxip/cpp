#include <vector>
#include <string>
// #include "./05.test.MoveStrings.h"
using namespace std;


void MoveStrings(vector<string>& src, vector<string>& dst)
{
    for (auto s : src)
    {
        dst.push_back(s);
    }
    src.clear();
}
