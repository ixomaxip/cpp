/*
    Task
    The probability that a machine produces a defective product is 1/3.
    What is the probability that the 1st defect is found during the 5th inspection?

    Input Format:
    1 3
    5

    Print a single line denoting the answer, rounded to a scale of 3 decimal places (i.e., 1.234 format).
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

int binomialCoefficients(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return binomialCoefficients(n - 1, k - 1) + binomialCoefficients(n - 1, k);
}

double negative_binomial(int x, int n, double p) {
    return binomialCoefficients(n - 1, x - 1) * pow(p, x) * pow(1.0 - p, n - x);
}

double geometric(int n, double p) {
    return negative_binomial(1, n, p); // i.e. 1 * pow(p, 1) * pow(1.0 - p, n - 1) => p*q^(n-1)
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num, den;
    int inspection;
    cin >> num;
    cin >> den;
    cin >> inspection;

    double p = num / double(den);
    cout << fixed << setprecision(3);
    cout << geometric(inspection, p) << endl;

    return 0;
}
