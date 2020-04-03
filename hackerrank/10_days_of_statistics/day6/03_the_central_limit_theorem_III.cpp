/*
    You have a sample of 100 values from a population with mean m=500
    and with standard deviation sd=80. Compute the interval that covers
    the middle 0.95 of the distribution of the sample mean;
    in other words, compute A and B such that P(A < x < B) = 0.95. Use the value of z=1.96. Note that z is the z-score.

    Input Format
        100
        500
        80
        0.95
        1.96

    Output Format
        Print the A & B rounded to a scale of 2 decimal places.
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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n_values; // = 100;
    double mean; // = 500;
    double sd; // = 80;
    double gamma; // = 0.95;
    double z_score; // = 1.96;
    cin >> n_values >> mean >> sd >> gamma >> z_score;
    

    
    cout << fixed << setprecision(2);
    cout << mean - z_score * sd / sqrt(n_values) << endl;
    cout << mean + z_score * sd / sqrt(n_values) << endl;
    return 0;
}
