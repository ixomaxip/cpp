#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name)
    {
        f_names[year] = first_name;
    }
    
    void ChangeLastName(int year, const string& last_name)
    {
        l_names[year] = last_name;
    }
    
    string GetFullName(int year)
    {
        const string first_name = find_name(f_names, year);
        const string last_name = find_name(l_names, year);

        if (first_name.empty() && last_name.empty())
        {
            return "Incognito";
        }
        else if (last_name.empty())
        {
            return first_name + " with unknown last name";
        }
        else if (first_name.empty())
        {
            return last_name + " with unknown first name";
        }
        return first_name + " " + last_name;
    }
private:
    map<int, string> f_names;
    map<int, string> l_names;
    string find_name(const map<int, string>& names, int year)
    {
        string name;
        auto last_change = names.upper_bound(year);
        name = last_change == begin(names) ? "" : prev(last_change)->second;
        return name;
    }

};