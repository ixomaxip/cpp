#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "./03.names2.cpp"

using namespace std;

int main() {
    cout << "Person 1:" << endl;
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


    cout << endl << "Person 2:" << endl;
    Person person2;

    person2.ChangeFirstName(1900, "Eugene");
    person2.ChangeLastName(1900, "Sokolov");
    person2.ChangeLastName(1910, "Sokolov");
    person2.ChangeFirstName(1920, "Evgeny");
    person2.ChangeLastName(1930, "Sokolov");
    cout << person2.GetFullNameWithHistory(1940) << endl;

    cout << endl << "Person 3:" << endl;
    Person person3;

    person3.ChangeFirstName(1965, "Polina");
    person3.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
    cout << person3.GetFullNameWithHistory(year) << endl;
    }

    person3.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
    cout << person3.GetFullNameWithHistory(year) << endl;
    }

    person3.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
    cout << person3.GetFullNameWithHistory(year) << endl;
    }

    person3.ChangeFirstName(1990, "Polina");
    person3.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person3.GetFullNameWithHistory(1990) << endl;

    person3.ChangeFirstName(1966, "Pauline");
    cout << person3.GetFullNameWithHistory(1966) << endl;

    person3.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
    cout << person3.GetFullNameWithHistory(year) << endl;
    }

    person3.ChangeLastName(1961, "Ivanova");
    cout << person3.GetFullNameWithHistory(1967) << endl;




    cout << endl << "Person4:" << endl;
    Person person4;

    person4.ChangeFirstName(1965, "Polina");
    person4.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person4.GetFullNameWithHistory(year) << endl;
    }

    person4.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person4.GetFullNameWithHistory(year) << endl;
    }

    person4.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person4.GetFullNameWithHistory(year) << endl;
    }

    person4.ChangeFirstName(1990, "Polina");
    person4.ChangeLastName(1990, "Volkova"); //-Sergeeva
    cout << person4.GetFullNameWithHistory(1990) << endl;

    person4.ChangeFirstName(1966, "Pauline");
    cout << person4.GetFullNameWithHistory(1966) << endl;

    person4.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person4.GetFullNameWithHistory(year) << endl;
    }

    person4.ChangeLastName(1961, "Ivanova");
    for (int year : {1960, 1967, 1990}) {
        cout << person4.GetFullNameWithHistory(year) << endl;
    }

    person4.ChangeFirstName(1901, "Polina");
    person4.ChangeLastName(1901, "Sergeeva");
    for (int year : {1900, 1960, 1967, 1990, 1991}) {
        cout << person4.GetFullNameWithHistory(year) << endl;
    }





    return 0;
}