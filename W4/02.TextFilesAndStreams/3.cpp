#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    const string path = "out.txt";
    ofstream fd_out(path);
    fd_out << "hello" << endl;
    ifstream fd_in(path);
    if (fd_in)
    {
        string line;
        while(getline(fd_in, line))
        {
            cout << line << endl;
        }
    }
    return 0;
}