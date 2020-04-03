/*
    A large elevator can transport a maximum of 9800 pounds.
    Suppose a load of cargo containing 49 boxes must be transported via the elevator.
    The box weight of this type of cargo follows a distribution with a mean of mu=205
    pounds and a standard deviation of sigma=15 pounds.
    Based on this information, what is the probability that all 49 boxes can be
    safely loaded into the freight elevator and transported?

    Input Format
        9800
        49
        205
        15

    Output Format
        Print the probability that the elevator can successfully transport all 49 boxes,
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
