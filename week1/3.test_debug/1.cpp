#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/* tests
 alpha beta gamma
 beta alpha gamma
 gamma alpha beta

 alpha beta alpha - 1 bug
 alpha alpha beta - 2 bug
 beta alpha alpha

 gamma gamma gamma
*/
int main()
{
    string a, b, c;

    cin >> a >> b >> c;
    if ( a < b && a < c)
    {
        cout << a << endl;
    }
    else if (b <= a && b <= c)
    {
        cout << b << endl;
    }
    else
    {
        cout << c << endl;
    }

    return 0;
}