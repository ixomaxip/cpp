#include <iostream>
#include <vector>
using namespace std;

/*
input
12
ADD 5 Salary
ADD 31 Walk
ADD 30 WalkPreparations
NEXT
DUMP 5
DUMP 28
NEXT
DUMP 31
DUMP 30
DUMP 28
ADD 28 Payment
DUMP 28

output
1 Salary
2 WalkPreparations Walk
0
0
2 WalkPreparations Walk
3 WalkPreparations Walk Payment
*/

enum cmd_code {none, add, next, dump};
cmd_code hashit(const string & cmd)
{
    if (cmd == "ADD") return cmd_code::add;
    if (cmd == "NEXT") return cmd_code::next;
    if (cmd == "DUMP") return cmd_code::dump;
    return cmd_code::none;
}

struct command {
    cmd_code cmd;
    int prm;
};

vector<vector<vector<string>>> get_empty_calendar()
{
    vector<vector<vector<string>>> c;
    for (auto  d : {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31})
    {
        vector<vector<string>> todos(d);
        c.push_back(todos);
    }

    return c;
}

int main()
{
    int N;
    cin >> N;

    vector<vector<vector<string>>> c = get_empty_calendar();
    int nxt = 0;
    vector<vector<string>>  curr_month = c[nxt];
    string cmd;
    for (int i = 0; i < N; ++i)
    {
        cin >> cmd;
        int day;
        string todo;
        switch (hashit(cmd))
        {
        case cmd_code::add:
            cin >> day;
            cin >> todo;
            curr_month[day-1].push_back(todo);
            break;
        case cmd_code::next:
            ++nxt;
            if (nxt > 11)
                nxt = 0;

            for (int d = 0; d < curr_month.size(); ++d)
            {
                if (d < c[nxt].size())
                {
                    c[nxt][d] = curr_month[d];
                }
                else
                {
                    c[nxt][c[nxt].size() - 1].insert(end(c[nxt][c[nxt].size() - 1]), begin(curr_month[d]), end(curr_month[d]));
                }                
            }
            curr_month = c[nxt];
            break;
        case cmd_code::dump:
            cin >> day;
            if (day > curr_month.size())
                break;
            cout << curr_month[day-1].size() << " ";
            for (auto todo : curr_month[day-1])
            {
                cout << todo << ' ';
            }
            cout << endl;
            break;
        case cmd_code::none:
            break;
        }
    }

    return 0;
}