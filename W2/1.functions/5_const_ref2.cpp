#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    const vector<string> v = {"hello"};
    // v.push_back("asd");
    // v[0][0] = 'H';
    cout << v[0] << endl;

    return 0;
}