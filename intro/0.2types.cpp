#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int x = -5;
    double pi = 3.1516926;
    bool logic = false;
    char symb = 'Z';

    string hw = "Hello world!";
    vector<int> nums = {1,3,5,7};
    cout << nums.size();
    cout << '\n';
    
    map<string, int> name_to_val;
    name_to_val["one"] = 1;
    name_to_val["two"] = 2;

    cout << "two is " << name_to_val["two"];
    
    
    cout << '\n';

    return 0;
}