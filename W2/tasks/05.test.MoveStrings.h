#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& src, vector<string>& dst);

struct test
{
    vector<string> src;
    vector<string> dst;
    vector<string> out_dst;
};


int main()
{
    vector<test> tests = 
    {
        {{"a", "b", "c"}, {"z"}, {"z", "a", "b", "c"}},
        {{"a", "b", "c"}, {}, {"a", "b", "c"}},
        {{}, {"z"}, {"z"}}
    };

    for ( auto t : tests)
    {
        MoveStrings(t.src, t.dst);
        if (t.src.size() == 0 && t.dst == t.out_dst)
        {
            cout << "Ok" << endl;
        }
        else
        {
                cout << "Error" << endl;
        }
        
    }
    
    return 0;
}
