#include <vector>
#include <string>
// #include "./06.test.vec_reverse.h"
using namespace std;


void Reverse(vector<int>& v)
{
    for(size_t i = 0; i < v.size() / 2; ++i)
    {
        int tmp = v[i];
        int r_idx = v.size() - 1 - i;
        v[i] = v[r_idx];
        v[r_idx] = tmp;
    }
}