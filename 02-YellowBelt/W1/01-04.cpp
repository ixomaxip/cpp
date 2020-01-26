#include <iostream>
#include <vector>
#include <string>
#include <set>


using namespace std;

void process_request_1(set<int>& numbers, const string& request_type, int request_data)
{
    if (request_type == "ADD")
    {
        numbers.insert(request_data);
    } else if (request_type == "REMOVE")
    {
        numbers.erase(request_data);
    } else if (request_type == "NEGATE")
    {
        if (numbers.count(request_data) == 1)
        {
            numbers.erase(request_data);
            numbers.insert(-request_data);
        }        
    }
}

void prt_set(const set<int>& numbers)
{
    for (auto n : numbers)
    {
        cout << n << ' ';
    }
    cout << endl;
}

int main()
{
    set<int> numbers = {1,2,3};
    process_request_1(numbers, "ADD", 8);
    prt_set(numbers);
    process_request_1(numbers, "NEGATE", 8);
    prt_set(numbers);
    process_request_1(numbers, "REMOVE", -8);
    prt_set(numbers);
    
    return 0;
}
