#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <tuple>
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

vector<double> ranks(const vector<double>& X) {
    vector<double> R(X.size(), 0.0);
    vector<pair<double, int>> T;
    for (size_t i = 0; i < X.size(); i++) {
        T.push_back(make_pair(X[i], i));
    }
    sort(begin(T), end(T), [](pair<double, int>& lh,  pair<double, int>& rh) {
            return abs(lh.first) < abs(rh.first);});
    
    int rank = 1;
    int n = 1;
    size_t i = 0;
    size_t j = 0;

    while (i < X.size())
    {
        j = i;
        while ((j < X.size() - 1) && (T[j].first == T[j+1].first)) {
            j++;
        }
        n = j - i + 1;
        for (int k = 0; k < n; k++){
            int idx = T[i+k].second;
            R[idx] = rank + (n - 1) * 0.5;
        }
        rank++;
        i += n;
    }
    
    return R;
}

// Sample Input
//     10
//     10 9.8 8 7.8 7.7 1.7 6 5 1.4 2 
//     200 44 32 24 22 17 15 12 8 4
// Sample Output
//     0.903
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N; //= 10;
    cin >> N;
    // vector<double> X = {10, 9.8, 8, 7.8, 7.7, 1.7, 6, 5, 1.4, 2};
    // vector<double> Y = {200, 44, 32, 24, 22, 17, 15, 12, 8, 4};
    vector<double> X(N), Y(N);
    for (auto& i : X) {cin >> i;}
    for (auto& i : Y) {cin >> i;}
    
    cout << fixed << setprecision(3);
    vector<double> rX = ranks(X);
    vector<double> rY = ranks(Y);
    cout << cov(rX, rY, N) / stddev(rX) / stddev(rY) << endl;

    return 0;
}
