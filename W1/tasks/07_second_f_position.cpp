#include <iostream>
#include <string>

using namespace std;

/*
Дана строка. Найдите в этой строке второе вхождение буквы f 
и выведите индекс этого вхождения. Если буква f в данной 
строке встречается только один раз, выведите число -1, 
а если не встречается ни разу, выведите число -2. 
Индексы нумеруются с нуля.
*/

/*
test:
comfort	    -1
coffee	     3
car	        -2
*/

int main()
{
    char ch = 'f';
    string s;
    cin >> s;

    int res = -2;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ch)
        {
            res++;
            if (res == 0)
            {
                res = i;
                break;
            }
        }
    }

    cout << res << endl;

    

    return 0;
}