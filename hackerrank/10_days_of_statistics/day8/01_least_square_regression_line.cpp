#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
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

double cov(const vector<double>& X, const vector<double>& Y, const size_t N) {
    double mX = mean(X);
    double mY = mean(Y);
    double sum = 0;
    for (size_t i = 0; i < N; i++) {
        sum += (X[i] - mX) * (Y[i] - mY);
    }
    return sum / N;
}

class linear_model 
{
public:
    linear_model() {};
    ~linear_model() {};
    void fit(const vector<double>& X, const vector<double>& Y, size_t N) {
        double sdX = stddev(X);
        double mX = mean(X);
        double mY = mean(Y);
        this->intercept = cov(X, Y, N) / sdX / sdX;
        this->coeff = mY - this->intercept * mX;
        return;
    }
    double predict(double x) {
        return this->intercept * x + this->coeff;
    }

    double intercept;
    double coeff;
};

int main() {
    size_t N = 5;
    // vector<double> X = {1, 2, 3, 4, 5};
    // vector<double> Y = {2, 1, 4, 3, 5};
    vector<double> X, Y;
    for (size_t i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
    }
    linear_model lm;
    lm.fit(X, Y, N);
    double pred = lm.predict(80);
    cout << fixed << setprecision(3);
    cout << pred << endl;

    return 0;
}
