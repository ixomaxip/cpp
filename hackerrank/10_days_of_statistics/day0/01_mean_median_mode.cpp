#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double mean(const vector<int>& arr) {
    int sum = 0;
    int count = 0;
    for (auto& i : arr) {
        sum += i;
        count++;
    }
    return sum / double(count);
}

double median(const vector<int>& arr) {
    int idx = arr.size() / 2;
    if (arr.size() % 2 == 0) {
        return (arr[idx - 1] + arr[idx]) / 2.0;
    }
    else {
        return arr[idx];
    }
}


int mode(const vector<int>& arr) {
    // array is already sorted 
    int n = arr[0];
    int mode = n;
    int count = 1;
    int cnt_mode = 1;
    for ( size_t i = 1; i < arr.size(); i++) {
        if (arr[i] == n) {
            count++;
        }
        else {
            if (count > cnt_mode) {
                cnt_mode = count;
                mode = n;
            }
            count = 1;
            n = arr[i];
        }
    }
    return mode;
}

// Sample Input
//  10
//  64630 11735 14216 99233 14470 4978 73429 38120 51135 67060
// Sample Output
//  43900.6
//  44627.5
//  4978

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    vector<int> v(N);
    for (auto& i : v) {cin >> i;}

    sort(begin(v), end(v), []( int& a,  int& b) {
            return abs(a) < abs(b);
        });
    // for (const auto& i : v) {
    //     cout << i << " ";
    // }

    cout << fixed << setprecision(1);
    cout << mean(v) << endl;
    cout << median(v) << endl;
    cout << mode(v) << endl;
    return 0;
}
