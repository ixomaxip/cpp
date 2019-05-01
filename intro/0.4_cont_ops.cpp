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

    vector<int> nums = {1,5,3,5,7,9,2};
    int q = 0;
    for (auto c : nums) 
    {
        if (c == 5)
            q++;
    }
    cout << "There are " << q << " fives";


    cout << '\n';
    return 0;
}