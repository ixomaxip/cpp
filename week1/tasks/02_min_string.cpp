#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2, s3;

    cin >> s1 >> s2 >> s3;

    string min_str = s1;
    for (auto s : {s2, s3})
    {
        if (s < min_str)
        {
            min_str = s;
        }
    }

    cout << min_str << endl;


    return 0;
}