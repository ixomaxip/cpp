#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <chrono>

using namespace std;
using namespace std::chrono;


struct person
{
    string name;
    string surname;
    int age;
};

vector<person> get_population()
{
    vector<person> p;
    for (int i = 0; i < 10000000; ++i)
    {
        p.push_back({"John", "Smith", 24});
    }

    return p;
}

void print_population_size(vector<person> p)
{
    cout << "P size is " << p.size() << endl;
}

int main()
{
    auto start = steady_clock::now();
    vector<person> people = get_population();
    auto finish = steady_clock::now();

    cout << "get_population "
        << duration_cast<milliseconds>(finish - start).count()
        << "ms" << endl;
    start = steady_clock::now(); 
    print_population_size(people);
    finish = steady_clock::now();
    cout << "print_population_size "
        << duration_cast<milliseconds>(finish - start).count()
        << "ms" << endl;

    return 0;
}