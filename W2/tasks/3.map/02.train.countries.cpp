#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
/*
input:
6
CHANGE_CAPITAL RussianEmpire Petrograd
RENAME RussianEmpire RussianRepublic
ABOUT RussianRepublic
RENAME RussianRepublic USSR
CHANGE_CAPITAL USSR Moscow
DUMP

output:
Introduce new country RussianEmpire with capital Petrograd
Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
Country RussianRepublic has capital Petrograd
Country RussianRepublic with capital Petrograd has been renamed to USSR
Country USSR has changed its capital from Petrograd to Moscow
USSR/Moscow
*/

enum cmd_code {none, ch_cap, ren, abt, dmp};
cmd_code hashit(const string& cmd)
{
    if (cmd == "CHANGE_CAPITAL") return ch_cap;
    if (cmd == "RENAME") return ren;
    if (cmd == "ABOUT") return abt;
    if (cmd == "DUMP") return dmp;
    return none;
}

int main()
{
    int Q;
    cin >> Q;
    string cmd;
    map<string, string> countries;
    for (int c = 0; c < Q; ++c)
    {
        cin >> cmd;
        cmd_code cc = hashit(cmd);
        if (cc == ch_cap) {
            string country, new_capital;
            cin >> country >> new_capital;
            if (countries.count(country) == 0){
                cout << "Introduce new country " << country 
                    << " with capital " <<  new_capital << endl;
            } else {
                const string & old_capital = countries[country];
                if (old_capital == new_capital){
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                } else {
                    cout << "Country " << country << " has changed its capital from " 
                        << old_capital << " to " << new_capital << endl;
                }
            }
            countries[country] = new_capital;
        } else if (cc == ren)
        {
            string old_name, new_name;
            cin >>  old_name >> new_name;
            if ((old_name == new_name) ||
                (countries.count(old_name) == 0) ||
                (countries.count(new_name) == 1)
                )
            {
                cout << "Incorrect rename, skip" << endl;
            }
            else
            {
                cout << "Country " << old_name 
                    << " with capital " << countries[old_name] 
                    << " has been renamed to " << new_name << endl;
                countries[new_name] = countries[old_name];
                countries.erase(old_name);
            }            
        } else if (cc == abt)
        {
            string country;
            cin >> country;
            if (countries.count(country) == 0)
            {
                cout << "Country " << " doesn't exist" << endl;
            }
            else
            {
                cout << "Country " << country << " has capital " << countries[country] << endl;
            }        

        } else if (cc == dmp)
        {
            if (countries.empty())
                cout << "There are no countries in the world" << endl;
            else
            {
                for (const auto& item :countries)
                {
                    cout << item.first << "/" << item.second << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}