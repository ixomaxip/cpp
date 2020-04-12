#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int diff = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        diff += arr[i][i] - arr[i][arr.size() - i - 1];
    }
    return abs(diff);
}

int main() {
    vector<vector<int>> v = {{11,2,4},{4,5,6},{10,8,-12}};
    cout << diagonalDifference(v) << endl;
    

    return 0;
}
