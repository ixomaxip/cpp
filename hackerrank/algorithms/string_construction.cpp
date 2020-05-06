#include <bits/stdc++.h>

using namespace std;
// Amanda has a string of lowercase letters that she wants to copy to a new string.
// She can perform the following operations with the given costs.
// She can perform them any number of times to construct a new string p:
//     - Append a character to the end of string p at a cost of 1 dollar.
//     - Choose any substring of p and append it to the end of p at no charge.


// Complete the stringConstruction function below.
int stringConstruction(string s) {
    string p = "";
    int cost = 0;
    for (auto& c : s) {
        if (p.find(c) == string::npos) {
            cost++;
        }
        p += c;
    }
    return cost;
}

int main()
{
    // string s = "abcabc"; // cost = 3
    // string s = "abab"; // cost = 2
    string s = "abcd"; // cost = 4
    

    int result = stringConstruction(s);

    cout << result << endl;

    return 0;
}
