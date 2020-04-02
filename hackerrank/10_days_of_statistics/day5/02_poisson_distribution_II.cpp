/*
    P(l, k) = l^k * exp(-l) / k!

The manager of a industrial plant is planning to buy a machine of either type A or type B. For each day’s operation:
    - The number of repairs, X, that machine  needs is a Poisson random variable with mean 0.88. 
        The daily cost of operating A is Ca = 160 + 40 * X^2.
    - The number of repairs, Y, that machine  needs is a Poisson random variable with mean 1.55.
        The daily cost of operating B is Cb = 128 + 40 * Y^2.
Assume that the repairs take a negligible amount of time and the machines are maintained nightly to ensure that they operate
like new at the start of each day. Find and print the expected daily cost for each machine.

    Input Format
        0.88 1.55

    Output Format
        Ca
        Cb
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

double poisson(double lambda, int k) {
    return pow(lambda, k) * exp(-lambda) / factorial(k);
}

double Ca(double x) {
    return 160 + 40 * x * x;
}

double Cb(double y) {
    return 128 + 40 * y * y;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double mean_x, mean_y;
    cin >> mean_x >> mean_y;
    double w_x = 0;
    double w_y = 0;
    //simulation
    for (int i = 0; i < 14; i++) {
        w_x += Ca(i) * poisson(mean_x, i);
        w_y += Cb(i) * poisson(mean_y, i);
    }

    cout << fixed << setprecision(3);
    cout << w_x << endl;
    cout << w_y << endl;
    // exact value
    // cout << 160 + 40 * (mean_x + mean_x * mean_x) << endl;
    // cout << 128.0 + 40.0 * (mean_y + mean_y * mean_y) << endl;
    return 0;
}
