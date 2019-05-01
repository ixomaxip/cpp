#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
    string s = "abcdefg";

    for (char c : s)
    {
        cout << c << "\n";
    }

    vector<string> nums = {"1","3","5","7","9","2"};
    for (auto c : nums)
    {
        cout << c << ", ";

    }


    cout << '\n';
    return 0;
}