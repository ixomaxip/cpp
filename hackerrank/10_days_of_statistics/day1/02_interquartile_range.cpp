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
// 6
// 6 12 8 10 20 16
// 5 4 3 2 1 5
// Sample Output
// 9.0

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    vector<int> arr(N);
    for (auto& i : arr) {cin >> i;}
    for (int i = 0; i < N; i++) {
        int freq;
        cin >> freq;
        for (int j = 1; j < freq; j++) {
            arr.push_back(arr[i]);
        }
    }
    sort(begin(arr), end(arr), []( int& a,  int& b) {
            return abs(a) < abs(b);
        });
    
    int split_idx = arr.size() / 2;
    int high_idx = arr.size() % 2 == 0 ? split_idx : split_idx + 1;
    auto arr_low = std::vector<int>(arr.begin(), arr.begin() + split_idx);
    auto arr_high = std::vector<int>(arr.begin() + high_idx, arr.end());
    cout << fixed << setprecision(1);
    cout << median(arr_high) - median(arr_low) << endl;

    return 0;
}
