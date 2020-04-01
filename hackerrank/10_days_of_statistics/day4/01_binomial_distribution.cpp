/*
    Task
    The ratio of boys to girls for babies born in Russia is 1.09:1. 
    If there is 1 child born per birth, what proportion of Russian families
    with exactly 6 children will have at least 3 boys?

    Input Format:
    1.09 1
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
    double boys, girls;
    cin >> boys;
    cin >> girls;

    double p = boys / (boys + girls);
    int n = 6;
    int x = 3;
    double sum = 0;
    for (int r = x; r <= n; r++) {
        sum += binomial(r, n, p);
    }
    cout << fixed << setprecision(3);
    // double result = sum / (1 - sum); //ratio
    cout << sum << endl;
    return 0;
}
