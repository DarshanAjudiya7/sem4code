#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void gaussElimination(vector<vector<double>>& mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int k = i+1; k < n; k++) {
            double factor = mat[k][i] / mat[i][i];
            for (int j = i; j <= n; j++)
                mat[k][j] -= factor * mat[i][j];
        }
    }
    vector<double> x(n);
    for (int i = n-1; i >= 0; i--) {
        x[i] = mat[i][n] / mat[i][i];
        for (int k = i-1; k >= 0; k--)
            mat[k][n] -= mat[k][i] * x[i];
    }
    for (int i = 0; i < n; i++)
        cout << "F" << i+1 << " = " << x[i] << endl;
}