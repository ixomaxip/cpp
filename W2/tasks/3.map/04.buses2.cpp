#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*
input:
4
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
2 Kokoshkino Marushkino


output:
New bus 1
New bus 2
Already exists for 1
New bus 3

*/

int main()
{
    int Q;
    cin >> Q;
    map<vector<string>, int> buses;
    int bus = 1;
    for (int i = 0; i < Q; ++ i)
    {
        int N;
        cin >> N;
        vector<string> stops(N);
        for (auto& stop : stops) {
            cin >> stop;
        }
        if (buses.count(stops) == 0) {
            buses[stops] = bus;
            cout << "New bus " << bus << endl;
            bus++;
        } else {
            cout << "Already exists for " << buses[stops] << endl;
        }
    }
 
    return 0;
}