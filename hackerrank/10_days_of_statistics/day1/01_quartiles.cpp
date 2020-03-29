#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double median(const vector<int>& arr) {
    int idx = arr.size() / 2;
    if (arr.size() % 2 == 0) {
        return (arr[idx - 1] + arr[idx]) / 2.0;
    }
    else {
        return arr[idx];
    }
}

// Sample Input
// 9
// 3 7 8 5 12 14 21 13 18
// Sample Output
// 6
// 12
// 16

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    vector<int> v(N);
    for (auto& i : v) {cin >> i;}

    sort(begin(v), end(v), []( int& a,  int& b) {
            return abs(a) < abs(b);
        });
    int split_idx = v.size() / 2;
    int high_idx = v.size() % 2 == 0 ? split_idx : split_idx + 1;
    auto v_low = std::vector<int>(v.begin(), v.begin() + split_idx);
    auto v_high = std::vector<int>(v.begin() + high_idx, v.end());
    cout << median(v_low) << endl;
    cout << median(v) << endl;
    cout << median(v_high) << endl;
    return 0;
}
