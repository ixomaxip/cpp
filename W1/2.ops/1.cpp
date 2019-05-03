#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int x = 5;
    x =6;

    cout << x << endl;

    string s = "foo";
    //full copy
    string t = s;

    t += " bar";

    cout << "s = " << s << endl;
    cout << "t = " << t << endl;

    vector<string> w = {"a", "b", "c"};
    vector<string> v;

    v = w;
    v[0] = "d";

    cout << w[0] << " " << w[1] << endl;
    cout << v[0] << " " << v[1] << endl;


    cout << endl;
    return 0;
}