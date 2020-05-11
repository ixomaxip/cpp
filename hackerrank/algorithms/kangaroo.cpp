#include <bits/stdc++.h>

using namespace std;

// You are choreographing a circus show with various animals.
// For one act, you are given two kangaroos on a number line
// ready to jump in the positive direction (i.e, toward positive infinity).
//     - The first kangaroo starts at location x1 and moves at a rate of v1 meters per jump.
//     - The second kangaroo starts at location x2 and moves at a rate of v2 meters per jump.
// You have to figure out a way to get both kangaroos at the same location at the same time
// as part of the show. If it is possible, return YES, otherwise return NO.

// For example, kangaroo 1 starts at x1 = 2 with a jump distance v1 = 1 and kangaroo 2 starts at x2 = 1 with a jump distance of v2 = 2
// After one jump, they are both at x = 3, (x1 + v1 = 2 + 1, x2 + v2 = 1 + 2), so our answer is YES.


string kangaroo(int x1, int v1, int x2, int v2) {
    if (v1 > v2 && (x2 - x1) % (v1 - v2) == 0) {
        return "YES";
    } else {
        return "NO";
    }
    // if ((x1 - x2) * (v1 - v2) > 0) {
        // return "NO";
    // }
    // return kangaroo(x1 + v1, v1, x2 + v2, v2);
}

vector<vector<int>> tests() {
    vector<vector<int>> ret;
    // ret.push_back({2, 1, 1, 2});
    // ret.push_back({1, 1, 2, 1});
    // ret.push_back({0, 3, 4, 2});
    // ret.push_back({0, 2, 5, 3});
    // ret.push_back({0, 0, 5, 3});
    ret.push_back({0, 2, 10000, 1});


    return ret;
}

int main()
{
    vector<vector<int>> ts = tests();
    for (const auto& t : ts) {
        string result = kangaroo(t[0], t[1], t[2], t[3]);
        cout << result << "\n";
    }

    return 0;
}
