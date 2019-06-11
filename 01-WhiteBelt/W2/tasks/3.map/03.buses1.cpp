#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
/*
input:
10
ALL_BUSES
BUSES_FOR_STOP Marushkino
STOPS_FOR_BUS 32K
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
STOPS_FOR_BUS 272
ALL_BUSES

output:
No buses
No stop
No bus
32 32K
Stop Vnukovo: 32 32K 950
Stop Moskovsky: no interchange
Stop Rumyantsevo: no interchange
Stop Troparyovo: 950
Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
Bus 32: Tolstopaltsevo Marushkino Vnukovo
Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
*/

enum cmd_code {none, nb, bfs, sfb, ab};
cmd_code hashit(const string& cmd)
{
    if (cmd == "NEW_BUS") return nb;
    if (cmd == "BUSES_FOR_STOP") return bfs;
    if (cmd == "STOPS_FOR_BUS") return sfb;
    if (cmd == "ALL_BUSES") return ab;
    return none;
}

int main()
{
    int Q;
    cin >> Q;
    string cmd;
    map<string, vector<string>> buses;
    map<string, vector<string>> stops;
    int stop_count;
    string stop, bus;
    for (int c = 0; c < Q; ++c)
    {
       cin >> cmd;
       cmd_code cc = hashit(cmd);
       switch (cc)
       {
        case nb:
            cin >> bus >> stop_count;
            // vector<string>& stops = buses_to_stops[bus];
            // stops.resize(stop_count);
            
            // for (string& stop : stops) {
            //     cin >> stop;
            //     stops_to_buses[stop].push_back(bus);
            // }
            for (int i = 0; i < stop_count; ++i)
            {
                cin >> stop;
                buses[bus].push_back(stop);
                stops[stop].push_back(bus);
            }
            break;
        case bfs:
            cin >> stop;
            if (stops.count(stop) == 0) {
                cout << "No stop" << endl;
            } else {
                for (const auto& b : stops[stop])
                {
                    cout << b << " ";
                }
                cout << endl;
            }
            break;
        case sfb:
            cin >> bus;
            if (buses.count(bus) == 0){
                cout << "No bus" << endl;
            } else {
                for (const auto & s : buses[bus]) {
                    cout << "Stop " << s << ": ";
                    if (stops[s].size() == 1) {
                        cout << "no interchange" << endl;
                    } else {
                        for (const auto & b : stops[s]) {
                            if (b != bus) {
                                cout << b << " ";
                            }
                        }
                        cout << endl;
                    }
                }
            }
            break;
        case ab:
            if (buses.empty())
            {
                cout << "No buses" << endl;
            } else {
                for (const auto & b : buses)
                {
                    cout << "Bus " << b.first << ": ";
                    for (const auto & s : b.second)
                    {
                        cout << s << " ";
                    }
                    cout << endl;
                }
            }
            break;
       }       
    }

    return 0;
}