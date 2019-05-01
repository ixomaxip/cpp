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

    vector<int> nums = {1,3,5,7,9,2};
    for (int c : nums)
    {
        cout << c << ", ";
        
    }


    cout << '\n';
    return 0;
}