/*
    In a certain plant, the time taken to assemble a car is a random variable, X,
    having a normal distribution with a mean of 20 hours and a standard deviation of 2 hours.
    What is the probability that a car can be assembled at this plant in:
        - Less than 19.5 hours?
        - Between 20 and 22 hours?

    Input Format
        20 2
        19.5
        20 22

    Output Format
        There are two lines of output. Your answers must be rounded to a scale of 3 decimal places (i.e., 1.234 format).
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;


double _erf(double x, int n=100) {
    double sum = 0;
    double dx = x / n;
    for (int i = 0; i < n; i++) {
        double middle = 0.5 * (i * dx + (i + 1) * dx);
        sum += exp(- middle * middle) * dx;
    }
    return 2 * sum / sqrt(M_PI);
}

double normal_cdf(double x, double mean, double stdev) {
    return 0.5 * (1.0 + _erf((x - mean) / stdev / sqrt(2.0)));
}

double phi(double x) {
    return exp(- 0.5 * x * x ) / sqrt(2.0 * M_PI);
}

double normal(double x, double mean, double stdev) {
    return phi((x - mean) / stdev) / stdev;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double mean, stdev;
    cin >> mean >> stdev;
    double lt;
    cin >> lt;
    double l_b, r_b;
    cin >> l_b >> r_b;
    
    cout << fixed << setprecision(3);
    cout << normal_cdf(lt, mean, stdev) << endl;
    cout << normal_cdf(r_b, mean, stdev) - normal_cdf(l_b, mean, stdev) << endl;
    return 0;
}
