#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string path = "input.txt";
    ifstream input(path);
    
    if (input)
    {
        string line;
        while (getline(input, line))
        {
            cout << line << endl;
        }
    }
        
    return 0;
}