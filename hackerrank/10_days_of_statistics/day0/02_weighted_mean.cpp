#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;



double weigthed_mean(const vector<int>& arr, const vector<int>& ws)
{
    int w_sum = 0;
    int sum = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        sum += arr[i] * ws[i];
        w_sum += ws[i];
    }
    return sum / double(w_sum);
}

// Sample Input
// 5
// 10 40 30 50 20
// 1 2 3 4 5

// Sample Output
// 32.0


int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;

    vector<int> arr(N);
    vector<int> ws(N);
    for (auto& i : arr) {cin >> i;}
    for (auto& i : ws) {cin >> i;}

    cout << fixed << setprecision(1);
    cout << weigthed_mean(arr, ws) << endl;

    return 0;
}
