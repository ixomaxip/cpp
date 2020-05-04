// Given set S = {1,2,3, ... , N}. Find two integers, A and B (where A < B),
// from set S such that the value of A&B is the maximum possible
// and also less than a given integer, K.
// In this case, & represents the bitwise AND operator.

// Input Format
//     The first line contains an integer, T, the number of test cases.
//     Each of the  subsequent lines defines a test case as  space-separated integers, N and K, respectively.
// Constraints
//     1 <= T <= 10^3
//     2 <= N <= 10^3
//     2 <= K <= N
// Output Format
//     For each test case, print the maximum possible value of A&B on a new line.

// Test case
// 3
// 5 2
// 8 5
// 2 2

// 1
// 4
// 0

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void bin(int n) {
    if (n > 1) {
        bin(n>>1);
    }
    cout << (n&1);
}

int solution(int n, int k) {
    int max_and = 0;
    for (int A = 1; A <= k; A++) {
        for (int B = A + 1; B <= n; B++) {
            if ((A&B) < k)
                max_and = max(max_and, A&B);
        }
    }
    return max_and;
}

int solution2(int n, int k) {
    if (k < 2)
        return 0;
    if (k == 2)
        return 1;
    if (((k - 1) & k) > ((k - 2) & (k - 1))) {
        return (k - 1) & k;
    } else {
        return (k - 2) & (k - 1);
    }
}


int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);
        int k = stoi(nk[1]);
        cout << solution2(n, k) << endl;
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
