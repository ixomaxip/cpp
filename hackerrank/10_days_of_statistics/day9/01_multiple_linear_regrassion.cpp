#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <tuple>
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
// matrix inverse(const matrix& X) {
//     return;
// }

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
    matrix test_X = get_matrix(q,  m);
    for (auto& row : test_X) {
        for (auto& col : row) {
            is >> col;
        }
    }

    return make_tuple(X, Y, test_X);    
}

void test_multiply() {
    matrix A = {{1,4,6}};
    matrix B = {{2,3}, {5,8}, {7,9}};
    prt_matrix(A);
    prt_matrix(B);
    prt_matrix(multiply(A, B));
    // 64 89
}


int main() {
    // matrix X, Y, test_X;
    // ifstream input("test_input");
    // tie(X, Y, test_X) = read(input);
    // // tie(X, Y, test_X) = read(cin);
    // matrix XT = transpose(X);
    // matrix XT_X = multiply(XT, X);
    test_multiply();

    // cout << endl;
    // prt_matrix(test_X);
    

    return 0;
}
