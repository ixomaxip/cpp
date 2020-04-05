#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


double mean(const vector<double>& arr) {
    int sum = 0;
    for (auto& i : arr) {
        sum += i;
    }
    return sum / double(arr.size());
}

double stddev(const vector<double>& arr) {
    double m = mean(arr);
    double sum = 0.0;
    for (const auto& i : arr) {
        double x = i - m;
        sum += x * x;
    }
    return sqrt(sum / arr.size());
}

double cov(const vector<double>& X, const vector<double>& Y, const int N) {
    double mX = mean(X);
    double mY = mean(Y);
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (X[i] - mX) * (Y[i] - mY);
    }
    return sum / N;
}

// Sample Input
//     10
//     10 9.8 8 7.8 7.7 7 6 5 4 2 
//     200 44 32 24 22 17 15 12 8 4
// Sample Output
//     0.612
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    vector<double> X(N), Y(N);
    for (auto& i : X) {cin >> i;}
    for (auto& i : Y) {cin >> i;}
    
    cout << fixed << setprecision(3);
    cout << cov(X, Y, N) / stddev(X) / stddev(Y) << endl;

    return 0;
}
