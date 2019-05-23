#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct Student
{
    string name;
    string lastname;
    int day;
    int month;
    int year;
};

int main()
{
    vector<Student> stds;
    string name, lastname;
    int d, m, y;

    int n;    
    cin >> n;    
    for (int i = 0; i < n; ++i)
    {
        cin >> name >> lastname >> d >> m >> y;
        stds.push_back(Student{name, lastname, d, m, y});
    }
    
    int qs;
    cin >> qs;
    for (int i = 0; i < qs; ++i)
    {
        string q;
        int numb;
        cin >> q >> numb;
        --numb;
        bool good_numb = numb >= 0 && numb < n;
        if (q == "name" && good_numb)
        {
            cout << stds[numb].name << " " << stds[numb].lastname << endl;
        }
        else if (q == "date" && good_numb)
        {
            cout << stds[numb].day << "." << stds[numb].month << "." << stds[numb].year << endl;
        }
        else
        {
            cout << "bad request" << endl;
        }
    }
 

    return 0;
}