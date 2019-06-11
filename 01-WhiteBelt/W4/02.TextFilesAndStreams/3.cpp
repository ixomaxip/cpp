#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void read_all(const string& path)
{
    ifstream fd_in(path);
    if (fd_in)
    {
        string line;
        while (getline(fd_in, line))
        {
            cout << line << endl;
        }
    }
}

int main()
{
    const string path = "out.txt";
    ofstream fd_out(path, ios::app);
    fd_out << "world" << endl;
    read_all(path);
    return 0;
}