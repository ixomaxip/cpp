#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/* tests
 alpha beta gamma
 beta alpha gamma
 gamma alpha beta

 alpha beta alpha
 alpha alpha beta
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
    else if (b < a && b < c)
    {
        cout << b << endl;
    }
    else if (c < a && c < b)
    {
        cout << c << endl;
    }

    return 0;
}