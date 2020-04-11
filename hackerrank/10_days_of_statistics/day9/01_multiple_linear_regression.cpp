#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <tuple>
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
using namespace std;


typedef vector<vector<double>> matrix;


matrix get_matrix(int n, int m) {
    matrix X(n, vector<double>(m));
    return X;
}


void prt_matrix(const matrix& M) {
    for (const auto& row : M) {
        for (const auto& col : row) {
            cout << col << "\t";
        }
        cout << endl;
    }
    cout << endl;
}


matrix multiply(const matrix& A, const matrix& B) {
    int rows = A.size();
    int cols = B[0].size();
    matrix C(rows, vector<double>(cols, 0.0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (size_t k = 0; k < A[0].size(); k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

matrix transpose(const matrix& X) {
    int rows = X.size();
    int cols = X[0].size();
    matrix Xtr(cols, vector<double>(rows));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Xtr[j][i] = X[i][j];
        }
    }
    // prt_matrix(Xtr);
    return Xtr;
}

matrix get_cofactor(const matrix X, int r, int c) {
    int n = X.size();
    matrix result = get_matrix(n - 1, n - 1);
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != r && col != c) {
                result[i][j++] = X[row][col];
                if (j == n -1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return result;
}


matrix inverse(const matrix& X) {
    matrix result = get_matrix(1,1);

    return result;
}

tuple<matrix, matrix, matrix> read(istream& is) {
    int m, n;
    is >> m >> n;
    matrix X = get_matrix(n, m+1);
    matrix Y = get_matrix(n, 1);


    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j == 0) {
                X[i][j] = 1.0;
            }
            else {
                double x_val;
                is >> x_val;
                X[i][j] = x_val;
            }
        }
        double y_val;
        is >> y_val;
        Y[i][0] = y_val;
    }

    int q;
    is >> q;
    matrix test_X = get_matrix(q,  m + 1);
    bool is_first = true;
    for (auto& row : test_X) {
        for (auto& col : row) {
            if (is_first) {
                is_first = false;
                col = 1.0;
            }
            else {
                is >> col;
            }
        }
        is_first = true;
    }

    return make_tuple(X, Y, test_X);    
}


void test_transpose() {
    cout << "transpose: ";
    matrix A = {{1,2,3}, {4,5,6}, {7,8,9}};
    matrix test_case = {{1,4,7}, {2,5,8}, {3,6,9}};
    matrix result = transpose(A);
    if (result == test_case) {
        cout << "OK" << endl;
    } else {
        cout << "Not OK" << endl;
    }
}

void test_multiply() {
    cout << "multiply: ";
    matrix A = {{1,4,6}};
    matrix B = {{2,3}, {5,8}, {7,9}};
    matrix result = multiply(A, B);
    matrix test_case = {{64,89}};
    if (result == test_case) {
        cout << "OK" << endl;
    } else {
        cout << "Not OK" << endl;
    }
    // 64 89
}

void test_cofactor() {
    cout << "cofactor: ";
    matrix A = {{1,2,3,4}, {4,5,6,7}, {7,8,9,0}, {0,9,8,7}};
    matrix result = get_cofactor(A, 1, 2);
    matrix test_case = {{1,2,4}, {7,8,0}, {0,9,7}};
    if (result == test_case) {
        cout << "OK" << endl;
    } else {
        cout << "Not OK" << endl;
    }
}

void run_tests() {
    test_transpose();
    test_multiply();
    test_cofactor();
}


int _main() {
    ifstream input("test_input");
    matrix X, Y, test_X;
    tie(X, Y, test_X) = read(input);
    
    matrix XT = transpose(X);
    // matrix XT_X = multiply(XT, X);
    matrix XT_X_inv = inverse(multiply(XT, X));
    matrix B = multiply(multiply(XT_X_inv, XT), Y);

    matrix test_Y = multiply(test_X, B);


    return 0;
}



// int main() {
//     run_tests();
//     // ifstream input("test_input");
//     // matrix X, Y, test_X;
//     // tie(X, Y, test_X) = read(input);
//     // // tie(X, Y, test_X) = read(cin);
//     // matrix XT = transpose(X);
//     // matrix XT_X = multiply(XT, X);
//     // prt_matrix(test_X);
    

//     return 0;
// }

TEST_CASE("Read data", "[read]") {
    ifstream input("test_input");
    matrix X, Y, test_X;
    tie(X, Y, test_X) = read(input);
    REQUIRE(X == matrix({
                         {1, 0.18, 0.89},
                         {1, 1.00, 0.26},
                         {1, 0.92, 0.11},
                         {1, 0.07, 0.37},
                         {1, 0.85, 0.16},
                         {1, 0.99, 0.41},
                         {1, 0.87, 0.47}
                        }));
    REQUIRE(Y == matrix({
                         {109.85},
                         {155.72},
                         {137.66},
                         {76.17},
                         {139.75},
                         {162.6},
                         {151.77}
                        }));
    REQUIRE(test_X == matrix({
                         {1, 0.49, 0.18},
                         {1, 0.57, 0.83},
                         {1, 0.56, 0.64},
                         {1, 0.76, 0.18}
                        }));
}

TEST_CASE("Matrix transpose:", "[transpose]") {
    REQUIRE(transpose({{1,2,3}, {4,5,6}, {7,8,9}}) == matrix({{1,4,7}, {2,5,8}, {3,6,9}}));
}

TEST_CASE("Matrix multiply:", "[multiply]") {
    REQUIRE(multiply({{1,4,6}}, {{2,3}, {5,8}, {7,9}}) == matrix({{64,89}}));
}