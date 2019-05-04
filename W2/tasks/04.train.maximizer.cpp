#include <iostream>
#include <vector>
#include <string>
// #include "./04.train.maximizer.test.h"

using namespace std;

void UpdateIfGreater(const int& first, int& second)
{
    second = max(first, second);
}
