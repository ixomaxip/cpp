#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

class Date
{
public:
    explicit Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    int GetYear() const
    {
        return year;
    }
    int GetMonth() const
    {
        return month;
    }
    int GetDay() const
    {
        return day;
    }
private:
    int year;
    int month;
    int day;
};

ostream& operator<<(ostream& stream, const Date& dt)
{
    stream << setw(4) << setfill('0') << dt.GetYear() << "-"
           << setw(2) << setfill('0') << dt.GetMonth() << "-"
           << setw(2) << setfill('0') << dt.GetDay();
    return stream;
}

bool operator<(const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear() == rhs.GetYear())
    {
        if (lhs.GetMonth() == rhs.GetMonth())
        {
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}

class Database {
public:
    void AddEvent(const Date& date, const string& event)
    {
        events[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event)
    {
        return events[date].erase(event);
    }
    int  DeleteDate(const Date& date)
    {
        int deleted = events[date].size();
        events.erase(date);
        return deleted;
    }
    void Find(const Date& date) const
    {
        if (events.count(date) > 0)
        {
            for (const auto& ev : events.at(date))
            {
                cout << ev << endl;
            }
        }        
    }
    void Print() const
    {
        for (const auto& item : events)
        {
            for (const auto& ev : item.second)
            {
                cout << item.first << " " << ev << endl;
            }
        }
    }
private:
    // struct comp //not necessary, just for fun
    // {
    //     bool operator()(const string& lhs, const string& rhs)
    //     {
    //         lexicographical_compare(begin(lhs), end(lhs), begin(rhs), end(rhs),
    //         [](char cl, char cr) { return tolower(cl) < tolower(cr); });
    //     }
    // };
    // map<Date, set<string, comp>> events;
    map<Date, set<string>> events;
};

bool valiDate(stringstream& stream, const string& str_dt)
{
    if (stream.peek() != '-')
    {
        return false;
    }
    else
    {
        stream.ignore(1);
        return true;
    }
    
}

Date parse_date(const string& date)
{
    stringstream ss(date);
    int y, m, d;
    char d1, d2;
    ss >> y >> d1 >> m >> d2 >> d;
    if (d1 != '-' || d2 != '-' || !ss || ss.peek() != EOF)
    {
        stringstream ss;
        ss << "Wrong date format: " << date;
        throw runtime_error(ss.str());
    }

    if (m < 1 or m > 12)
    {
        string err = "Month value is invalid: " + to_string(m);
        throw runtime_error(err);
    }
    if (d < 1 or d > 31)
    {
        string err = "Day value is invalid: " + to_string(d);
        throw runtime_error(err);
    }   

    return Date(y, m, d);
}


void exec_cmd(const string& command, Database& db)
{
    stringstream ss(command);
    string cmd;
    string str_date, ev;
    ss >> cmd >> str_date >> ev;
    if (cmd == "Add")
    {
        // string str_date, ev;
        // ss >> str_date >> ev;
        Date dt = parse_date(str_date);
        db.AddEvent(dt, ev);
    }
    else if (cmd == "Del")
    {
        // string str_date, ev;
        // ss >> str_date >> ev;
        Date dt = parse_date(str_date);
        if (ev.empty())
        {
            int N = db.DeleteDate(dt);
            cout << "Deleted " << N << " events" << endl;
        }
        else
        {
            bool res = db.DeleteEvent(dt, ev);
            if (res) {cout << "Deleted successfully" << endl;}
            else {cout << "Event not found" << endl;}           
        }        
    }
    else if (cmd == "Find")
    {
        // string str_date;
        // ss >> str_date;
        Date dt = parse_date(str_date);
        db.Find(dt);
    }
    else if (cmd == "Print")
    {
        db.Print();
    }
    else if (cmd == ""){}
    else
    {
        string err = "Unknown command: " + cmd;
        throw runtime_error(err);
    }
}

int main()
{
    Database db;
    
    string command;
    while (getline(cin, command))
    {
        try
        {
            exec_cmd(command, db);
        }
        catch(const exception& e)
        {
            cout << e.what() << endl;
            return 1;
        }
    }

return 0;
}


