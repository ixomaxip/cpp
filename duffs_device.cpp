#include <iostream>

int main() {
    int n = 61;
    int cnt = n / 4;
    int i = 0;

    switch (n % 4) {
        case 0:
            do {
                ++i;
        case 3: ++i;
        case 2: ++i;
        case 1: ++i;
            } while (cnt-- > 0);
    }

    std::cout << i << std::endl;
}