#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    vector<int> chars(26, 0);
    for (auto& c : s1) {
        chars[c - 'a']++;
    }
    for (auto& c : s2) {
        if (chars[c - 'a'] > 0)
            return "YES";
    }

    return "NO";
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string s1 = "hi";
    string s2 = "world";

    string result = twoStrings(s1, s2);

    cout << result << endl;

    return 0;
}
