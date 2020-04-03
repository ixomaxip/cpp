/*
    The final grades for a Physics exam taken by a large group of
    students have a mean of mu=70 and a standard deviation of sigma=70.
    If we can approximate the distribution of these grades by
    a normal distribution, what percentage of the students:
        - Scored higher than 80 (i.e., have a grade > 80)?
        - Passed the test (i.e., have a grade >= 60)?
        - Failed the test (i.e., have a grade < 60)?
    Find and print the answer to each question on a new line, rounded to a scale of  decimal places.

    Input Format
        70 10
        80
        60

    Output Format
        There are three lines of output. Your answers must be rounded to a scale of 2 decimal places (i.e., 1.23 format).
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
    double high_grade;
    cin >> high_grade;
    double pass_grade;
    cin >> pass_grade;
    
    cout << fixed << setprecision(2);
    cout << (1.0 - normal_cdf(high_grade, mean, stdev)) * 100.0 << endl;
    cout << (1.0 - normal_cdf(pass_grade, mean, stdev)) * 100.0 << endl;
    cout << normal_cdf(pass_grade, mean, stdev) * 100.0 << endl;
    return 0;
}
