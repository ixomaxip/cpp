#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


double mean(const vector<int>& arr) {
    int sum = 0;
    for (auto& i : arr) {
        sum += i;
    }
    return sum / double(arr.size());
}

double std_dev(const vector<int>& arr) {
    double m = mean(arr);
    double sum = 0.0;
    for (const auto& i : arr) {
        double x = i - m;
        sum += x * x;
    }
    return sqrt(sum / arr.size());
}

// Sample Input
// 5
// 10 40 30 50 20
// Sample Output
// 14.1

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    vector<int> arr(N);
    for (auto& i : arr) {cin >> i;}
    
    cout << fixed << setprecision(1);
    cout << std_dev(arr) << endl;

    return 0;
}
