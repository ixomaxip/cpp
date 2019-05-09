#include <iostream>
#include <vector>
using namespace std;

/*
input
8
COME 5
WORRY 1
WORRY 4
COME -2
WORRY_COUNT
COME 3
WORRY 3
WORRY_COUNT
output
1
2
*/

enum cmd_code {none, worry, quiet, come, worry_count};
cmd_code hashit(const string & cmd)
{
    if (cmd == "WORRY") return worry;
    if (cmd == "QUIET") return quiet;
    if (cmd == "COME") return come;
    if (cmd == "WORRY_COUNT") return worry_count;
    return none;
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