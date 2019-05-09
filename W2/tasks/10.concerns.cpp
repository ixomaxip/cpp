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

int main()
{
    int N;
    cin >> N;

    vector<command> commands;
    for (int i = 0; i < N; ++i)
    {
        string cmd;
        int prm;
        cin >> cmd;
        cmd_code c = hashit(cmd);
        if (c != worry_count)
            cin >> prm;
        commands.push_back({c, prm});
    }

    vector<int> qp;
    int worried = 0; 
    for (int i = 0; i < commands.size(); ++i)
    {
        switch (commands[i].cmd)
        {
        case worry_count:
            worried = 0; 
            for (auto j : qp) worried += j;
            cout << worried << endl;
            break;
        case worry:
            qp[commands[i].prm] = 1;
            break;
        case quiet:
            qp[commands[i].prm] = 0;
            break;
        case come:
            qp.resize(qp.size() + commands[i].prm, 0);
            break;
        }
    }

    return 0;
}