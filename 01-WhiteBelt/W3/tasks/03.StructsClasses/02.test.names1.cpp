#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "./02.names1.cpp"

using namespace std;

int main() {
    Person person;  

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");

    for (int year : {1900, 1965, 1990}) {
        cout << year << " " << person.GetFullName(year) << endl;
    }  

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << year << " " << person.GetFullName(year) << endl;
    }  

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << year << " " << person.GetFullName(year) << endl;
    }
    return 0;
}