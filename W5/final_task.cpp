#include <iostream>
#include <string>
#include <map>
#include <vector>
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

bool operator<(const Date& lhs, const Date& rhs)
{

}

class Database {
public:
    void AddEvent(const Date& date, const string& event)
    {

    }
    bool DeleteEvent(const Date& date, const string& event);
    int  DeleteDate(const Date& date);

    void Find(const Date& date) const;

    void Print() const;
private:
    map<Date, vector<string>> events;

};

void valiDate(stringstream& stream, const string& str_dt)
{
    if (stream.peek() != '-')
    {
        stringstream ss;
        ss << "Wrong date format: " << str_dt;
        throw runtime_error(ss.str());
    }
    stream.ignore(1);
}

ostream& operator<<(ostream& stream, const Date& dt)
{
    stream << setw(4) << setfill('0') << dt.GetYear() << "-"
           << setw(2) << setfill('0') << dt.GetMonth() << "-"
           << setw(2) << setfill('0') << dt.GetDay();
}

Date parse_date(const string& date)
{
    stringstream ss(date);
    int y, m, d;
    ss >> y;
    valiDate(ss, date);
    ss >> m;
    valiDate(ss, date);
    ss >> d;

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


void parse_cmd(const string& command)
{
    stringstream ss(command);
    string cmd;
    ss >> cmd;

    if (cmd == "Add")
    {
        string str_date;
        ss >> str_date;
        Date dt = parse_date(str_date);
        
        string ev;
        ss >> ev;

        cout << dt << " ev: " << ev << endl;

        // db.AddEvent(dt, ev);
    }
    else if (cmd == "Del")
    {
        
    }
    else if (cmd == "Find")
    {
        
    }
    else if (cmd == "Print")
    {
        
    }
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
            parse_cmd(command);
        }
        catch(const exception& e)
        {
            cout << e.what() << endl;
        }
        
        
    }

return 0;
}