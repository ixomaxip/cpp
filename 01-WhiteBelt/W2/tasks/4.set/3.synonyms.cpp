#include <iostream>
#include <map>
#include <string>
#include <set>
// #include "./2.test.map_values.h"

using namespace std;
/*
input:
8
ADD program code
COUNT cipher
ADD code cipher
COUNT code
COUNT program
CHECK code program
CHECK program cipher
CHECK cpp java

output:
0
2
1
YES
NO
NO

*/

enum cmd_code {none, add, cnt, chk};
cmd_code hashit(const string& cmd)
{
    if (cmd == "ADD") return add;
    if (cmd == "COUNT") return cnt;
    if (cmd == "CHECK") return chk;
    return none;
}

int main()
{
    int Q;
    cin >> Q;
    map<string, set<string>> dict;
    while (Q-- > 0)
    {
        string cmd, w1, w2;
        cin >> cmd;
        switch (hashit(cmd))
        {
        case add:
            cin >> w1 >> w2;
            dict[w1].insert(w2);
            dict[w2].insert(w1);
        break;
        case cnt:
            cin >> w1;
            cout << dict[w1].size() << endl;
        break;
        case chk:
            cin >> w1 >> w2;
            if (dict[w1].count(w2) > 0 || dict[w2].count(w1) > 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            
        break;
        }

    }
    return 0;
}