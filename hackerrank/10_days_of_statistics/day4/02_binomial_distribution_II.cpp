/*
    Task
    A manufacturer of metal pistons finds that,
    on average, 12% of the pistons they manufacture are rejected
    because they are incorrectly sized.
    What is the probability that a batch of 10 pistons will contain:
        1. No more than 2 rejects?
        2. At least 2 rejects?
    
    Input Format:
        12 10
    Output Format:
        Print the answer to each question on its own line:
            1. The first line should contain the probability that a batch of 10 pistons will contain no more than 2 rejects.
            2. The second line should contain the probability that a batch of 10 pistons will contain at least 2 rejects.
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

double binomial(int x, int n, double p) {
    return binomialCoefficients(n ,x) * pow(p, x) * pow((1.0 - p), n - x);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double percent, batch;
    cin >> percent;
    cin >> batch;

    double p = percent / 100.0;
    int n = 10;
    int x = 2;
    double sum1, sum2 = 0;
    for (int r = 0; r <= n; r++) {
        if (r <= x)
            sum1 += binomial(r, n, p);
        if (r >= x)
            sum2 += binomial(r, n, p);
    }
    cout << fixed << setprecision(3);
    cout << sum1 << endl;
    cout << sum2 << endl;
    return 0;
}
