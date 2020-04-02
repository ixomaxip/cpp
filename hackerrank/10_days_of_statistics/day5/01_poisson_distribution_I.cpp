/*
    P(l, k) = l^k * exp(-l) / k!


    A random variable, X, follows Poisson distribution with mean of 2.5.
    Find the probability with which the random variable X is equal to 5.

    Input Format
        2.5
        5

    Output Format
        Print a single line denoting the answer, rounded to a scale of 3 decimal places (i.e., 1.234 format).
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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double lambda;
    int k;
    cin >> lambda;
    cin >> k;
    cout << fixed << setprecision(3);
    cout << poisson(lambda, k) << endl;
    return 0;
}
