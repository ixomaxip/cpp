#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <tuple>
#include <exception>
#include <stdexcept>

//tests
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"


using namespace std;


typedef vector<vector<double>> matrix;


matrix get_matrix(int n, int m) {
    matrix X(n, vector<double>(m));
    return X;
}


matrix get_eye(int n) {
    matrix result = get_matrix(n, n);
    for (int i = 0; i < n; i++) {
        result[i][i] = 1.0;
    }
    return result;
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

matrix get_minor(const matrix X, int r, int c) {
    int n = X.size();
    matrix result = get_matrix(n - 1, n - 1);
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != r && col != c) {
                result[i][j++] = X[row][col];
                if (j == (n - 1)) {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return result;
}

double determinant(const matrix& X) {
    double det = 0.0;
    int n = X.size();
    if (n == 1) {
        return X[0][0];
    }
    
    int sign = 1;
    for (int i = 0; i < n; i++) {
        matrix m = get_minor(X, 0, i);
        det += sign * X[0][i] * determinant(m);
        sign = -sign;
    }
    return det;
}

matrix get_adjoint(const matrix& X) {
    int n = X.size();
    matrix result = get_matrix(n, n);
    int sign = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix m = get_minor(X, i, j);
            sign = ((i + j) % 2 ==0) ? 1 : -1;
            result[j][i] = sign * determinant(m);
        }
    }
    return result;
}

matrix inverse(const matrix& X) {
    int n = X.size();
    double det = determinant(X);
    matrix result = get_matrix(n, n);

    if (det == 0) {
        return matrix({{0}});
    }
    matrix adjoint = get_adjoint(X);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = adjoint[i][j] / det;
        }
    }

    return result;
}

tuple<matrix, matrix, matrix> read_data(istream& is) {
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
    matrix _X = get_matrix(q,  m + 1);
    bool is_first = true;
    for (auto& row : _X) {
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

    return make_tuple(X, Y, _X);    
}

matrix calc(const matrix& X, const matrix& Y, const matrix& _X) {
    matrix XT = transpose(X);
    matrix XTX = multiply(XT, X);
    matrix XTXinv = inverse(XTX);
    matrix XTXinv_XT = multiply(XTXinv, XT);
    matrix B = multiply(XTXinv_XT, Y);
    matrix _Y = multiply(_X, B);

    return _Y;
}

int _main() {
    ifstream input("test_input");
    matrix X, Y, _X;
    tie(X, Y, _X) = read_data(input);

    matrix test_Y = calc(X, Y, _X);


    return 0;
}

TEST_CASE("Read data", "[read]") {
    ifstream input("test_input");
    matrix X, Y, test_X;
    tie(X, Y, test_X) = read_data(input);
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

TEST_CASE("Matrix transpose", "[transpose]") {
    REQUIRE(transpose({{1,2,3}, {4,5,6}, {7,8,9}}) == matrix({{1,4,7}, {2,5,8}, {3,6,9}}));
}

TEST_CASE("Matrix multiply", "[multiply]") {
    REQUIRE(multiply({{1,4,6}}, {{2,3}, {5,8}, {7,9}}) == matrix({{64,89}}));
}

TEST_CASE("Matrix ones", "[ones]") {
    REQUIRE(get_eye(3) == matrix({{1,0,0}, {0,1,0}, {0,0,1}}));
}

TEST_CASE("Matrix minor", "[minor]") {
    matrix A = {{1,2,3,4},
                {4,5,6,7},
                {7,8,9,0},
                {0,9,8,7}};
    matrix res = get_minor(A, 1, 2);
    matrix req = {{1,2,4},
                  {7,8,0},
                  {0,9,7}};
    REQUIRE(res == req);
}

TEST_CASE("Matrix adjoint", "[adjoint]") {
    matrix A = {{   5,  -2,  2,  7},
                {   1,   0,  0,  3},
                {  -3,   1,  5,  0},
                {   3,  -1, -9,  4}};
    matrix res = get_adjoint(A);
    matrix req = {{-12,76,-60,-36},
                  {-56,208,-82,-58},
                  {4,4,-2,-10},
                  {4,4,20,12}};
    REQUIRE(res == req);
}

TEST_CASE("Matrix determinant", "[determinant]") {
    SECTION( "1x1 matrix" ) {
        matrix m({{5}});
        REQUIRE(determinant(m) == 5.0);
    }
    SECTION("2x2 matrix") {
        matrix m({{1,2}, {3,4}});

        REQUIRE(determinant(m) == -2.0);
    }
    
    SECTION("Ones") {
        matrix m = get_eye(4);

        REQUIRE(determinant(m) == 1.0);
    }
    SECTION("singular matrix det") {
        matrix m({{1,0,0,0},
                  {1,0,0,0},
                  {0,0,1,0},
                  {0,0,0,1}});

        REQUIRE(determinant(m) == 0.0);
    }
    SECTION("simple matrix det") {
        matrix m({{-2,2,-3},
                  {-1,1,3},
                  {2,0,-1}});

        REQUIRE(determinant(m) == 18.0);
    }
}

TEST_CASE("Matrix inverse", "[inverse]") {
    SECTION("eye") {
        int N = 5;
        matrix res = inverse(get_eye(N));
        REQUIRE(res == get_eye(N));
    }
    SECTION("2x2 matrix") {
        matrix X({{1,2}, {3,4}});
        matrix X_inv = inverse(X);
        REQUIRE(multiply(X, X_inv) == get_eye(X.size()));
    }
}

TEST_CASE("Full computation: Y = X * B", "[full]") {
    matrix X = {{   1,   5,   7},
                {   1,   6,   6},
                {   1,   7,   4},
                {   1,   8,   5},
                {   1,   9,   6}};
    
    matrix Y = {{10},
                {20},
                {60},
                {40},
                {50}};
    
    matrix _X = {{1, 5, 5}};

    matrix XT = transpose(X);
    matrix XTX = multiply(XT, X);
    matrix XTXinv = inverse(XTX);
    matrix XTXinv_XT = multiply(XTXinv, XT);
    matrix B = multiply(XTXinv_XT, Y);
    matrix _Y = multiply(_X, B);
    SECTION("XT * X") {
        matrix req = {{   5,  35,  28},
                      {  35, 255, 193},
                      {  28, 193, 162}};
        REQUIRE(XTX == req);
    }
    SECTION("(XT * X)^-1") {
        matrix req = {{  18.8884,   -1.23721,    -1.7907},
                      { -1.23721,    0.12093,  0.0697674},
                      {  -1.7907,  0.0697674,   0.232558}};
        REQUIRE(XTXinv == req);
    }
    SECTION("(XT * X)^-1 * XT") {
        matrix req = {{  0.167442,     0.72093,    3.06512,   0.0372093,   -2.9907},
                      { -0.144186,  -0.0930233,  -0.111628,   0.0790698,  0.269767},
                      {  0.186047,   0.0232558,  -0.372093,  -0.0697674,  0.232558}};
        REQUIRE(XTXinv_XT == req);
    }

    SECTION("B = (XT * X)^-1 * XT * Y") {
        matrix req = {{  51.9535},
                      {  6.65116},
                      { -11.1628}};
        REQUIRE(B == req);
    }
    SECTION("_Y = _X * B") {
        matrix req = {{29.39535}};
        REQUIRE(_Y == req);
    }
    
}