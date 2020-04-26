#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Sample Input
//     3
//     12
//     5
//     7

// Sample Output
//     Not prime
//     Prime
//     Prime

// Sample Input
    // 1
    // 2038074743
// Sample Output
//     Prime

vector<int> read_numbers() {
    int N;
    cin >> N;
    vector<int> ns(N);
    for (auto& n : ns) {
        cin >> n;
    }
    return ns;
}

bool is_prime(int n) {
    // n = 2038074743 : 8471ms    
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            cout << i << endl;
            return false;
        }
    }    
    return true;

}


bool is_prime2(int n) {
    // naive: n = 2038074743 : 8471ms    
    if (n <= 3) {
        return n > 1;
    }

    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            cout << i << endl;
            return false;
        }
    }    
    return true;

}

int main() {
    // vector<int> ns = read_numbers();
    vector<int> ns = {2038074743};

    for (const auto& n : ns) {
        auto start = high_resolution_clock::now();
        is_prime2(n) ? cout << "Prime" << endl :
                      cout << "Not prime" << endl;
        auto finish = high_resolution_clock::now();
        auto d_ms = (duration<long, micro>) duration_cast<milliseconds>(finish - start);
        cout << "n = " << n << " : " << d_ms.count() << "mcs" << endl;
    }

    return 0;
}
