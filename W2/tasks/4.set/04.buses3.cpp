#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
/*
input:
5
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
2 Kokoshkino Marushkino
2 Kokoshkino Kokoshkino


output:
New bus 1
New bus 2
Already exists for 1
Already exists for 1
Already exists for 2

*/

int main()
{
    int Q;
    cin >> Q;
    map<set<string>, int> buses;
    int bus = 1;
    while (Q-- > 0)
    {
        int N;
        cin >> N;
        set<string> stops;
        while (N-- > 0)
        {
            string stop;
            cin >> stop;
            stops.insert(stop);
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