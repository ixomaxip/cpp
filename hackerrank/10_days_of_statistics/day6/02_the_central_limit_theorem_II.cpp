/*
    The number of tickets purchased by each student for the University X vs. University Y football game
    follows a distribution that has a mean of m=2.4 and a standard deviation of sd=2.0.

    A few hours before the game starts, 100 eager students line up to purchase last-minute tickets. If there are only 250 tickets left,
    what is the probability that all 100 students will be able to purchase tickets?

    Input Format
        250
        100
        2.4
        2.0

    Output Format
        Print the probability that 100 students can successfully purchase the remaining 250 tickets,
        rounded to a scale of 4 decimal places (i.e., 1.2345 format).
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
    double max_weight;
    int n_boxes;
    double mean_weight;
    double s_weight;
    cin >> max_weight >> n_boxes >> mean_weight >> s_weight;
    
    double mean_sum = mean_weight * n_boxes;
    double s_sum = s_weight * sqrt(n_boxes);
    
    cout << fixed << setprecision(4);
    cout << normal_cdf(max_weight, mean_sum, s_sum)<< endl;
    return 0;
}
