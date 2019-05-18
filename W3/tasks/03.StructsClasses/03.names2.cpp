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

        return get_full_name(first_name, last_name);
    }
    string GetFullNameWithHistory(int year)
    {
        const string first_name = joined_history(get_history(f_names, year));
        const string last_name = joined_history(get_history(l_names, year));

        return get_full_name(first_name, last_name);
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
    
    vector<string> get_history(const map<int, string>& names, int year)
    {
        vector<string> hist;
        auto last_change = names.upper_bound(year);
        while (last_change != begin(names))
        {
            hist.push_back(prev(last_change)->second);
            last_change = prev(last_change);
        }

        return hist;
    }

    string get_full_name(string first_name, string last_name)
    {
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
        } else {
            return first_name + " " + last_name;
        }
    }

    string joined_history(vector<string> names)
    {
        if (names.empty())
        {
            return "";
        }
        string curr_name = names[0];
        int cnt = 0;
        string hist_names;
        for (int i = 1; i < names.size(); ++i)
        {
            if (names[i] != names[i-1])
            {
                name += (i == 1) ? " (" : ", ";
                name += names[i];
                ++cnt;
            }
        }
        if (cnt > 0)
        {
            name += ")";
        }
        return name;
    }

};