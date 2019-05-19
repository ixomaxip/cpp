#include <iostream>
#include <string>
#include <vector>
using namespace std;

int compute_distance(const string& src, const string& dst )
{
    return src.length() - dst.length();
}

class Route
{
public:
    Route()
    {
        src = "Msc";
        dst = "SPb";
        upd_len();
        cout << "Default constructor" << endl;
    }
    Route(const string& new_src, const string& new_dst)
    {
        src = new_src;
        dst = new_dst;
        upd_len();
        cout << "constructor\n";
    }
    ~Route()
    {
        // for (const string& entr : compute_distance_log)
        // {
        //     cout << entr << endl;
        // }
        cout << "destructor\n";
    }
    string get_src() const
    {
        return src;
    }
    string get_dst() const
    {
        return dst;
    }
    void set_src(const string& new_src)
    {
        src = new_src;
        upd_len();
    }
    void set_dst(const string& new_dst)
    {
        dst = new_dst;
        upd_len();
    }
private:
    void upd_len()
    {
        len = compute_distance(src, dst);
        compute_distance_log.push_back(
            src + " - " + dst);
    }
    string src;
    string dst;
    int len;    
    vector<string> compute_distance_log;
};

void prt_route(const Route& rt)
{
    cout << rt.get_src() << "-" << rt.get_dst() << endl;
}

Route get_route()
{
    cout << 1 << endl;
    return {};
}

int main()
{
    get_route();
    cout << 2 << endl;
    return 0;
}