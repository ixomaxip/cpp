#include <iostream>
#include <vector>
using namespace std;

/*
input
5
7 6 3 0 9
output
3
0 1 4
*/

int main()
{
    int N;
    vector<int> tmps;

    cin >> N;
    int i = 0;
    int sum = 0;
    while (i < N)
    {
        int t;
        cin >> t;
        sum += t;
        tmps.push_back(t);
        ++i;
    }

    int mean = sum / N;
    vector<int> out;
    for (int i = 0; i < tmps.size(); ++i)
    {
        if (tmps[i] > mean)
        {
            out.push_back(i);
        }
    }

    cout << out.size() << endl;
    for (auto i : out)
    {
        cout << i << ' ';
    }
    cout << endl;



    return 0;
}