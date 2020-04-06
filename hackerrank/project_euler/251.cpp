#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

/*
    A triplet of positive integers (a,b,c) is called a Cardano Triplet if it satisfies the condition:
        (a + b * c^(0.5))^(1/3) = (a - b * c^(0.5))^(1/3
    For example, (2,1,5) is a Cardano Triplet.
    There exist 149 Cardano Triplets for which a+b+c <= 1000.
    
    Find how many Cardano Triplets exist such that a+b+c <= n.

    Sample Input 0
        2
        8
        1000
    Sample Output 0
        1
        149

    Sample Input 1
        2
        999999069
        999999550
    Sample Output 1
        172332336
        172332416
*/

/* Trick
a = 2 + 3 * k
b^2 * c = (k + 1)^2 * (8 * k + 5)
*/

int count_cardano(int N) {        
    int count = 0;
    int cnt_loop = 0;
    for (int k = 0; 2 + 3 * k <= N; k++) {
        int a = 2 + 3 * k;
        // int b2c = (k + 1) * (k + 1) * (8 * k + 5);
        for (int b = 1; b <= N - a; b++) {
            cnt_loop++;
            double c = (k + 1.0) * (k + 1) * (8 * k + 5) / b / b;
            if ((floor(c) == ceil(c)) && (a + b + c <= N)) {
                count++;
            }
        }
    }
    cout << "interior loop count: " << cnt_loop << endl;
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto start = steady_clock::now();
    int N = 30000;
    int count = count_cardano(N);
    auto finish = steady_clock::now();
    cout << "count: " << count << endl;
    cout << "n = " << N << " : " << duration_cast<milliseconds>(finish - start).count() << "ms" << endl;

    return 0;
}
