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
        ofstream out("output.txt");
        string line;
        while (getline(input, line))
        {
            out << line << endl;
        }
    }
        
    return 0;
}