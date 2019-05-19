#include <iostream>
using namespace std;

int compute_distance(const string& src, const string& dst )
{
    return src.length() - dst.length();
}

class Route
{
public:
    string get_src()
    {
        return src;
    }
    string get_src()
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
        src = new_dst;
        upd_len();
    }
private:
    void upd_len()
    {
        len = compute_distance(src, dst);
    }
    string src;
    string dst;
    int len;    
};


int main()
{

}