/*
 * Author: 
 *      Ghazal Rabiei
 *      Mohsen Dehbashi
 *
 * Gaussian elimination solver for linear systems Ax = b
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPS = 1e-9;

/**
 * Status of a linear system solution.
 */
enum class SolveStatus {
    UNIQUE,
    MULTIPLE,
    INCONSISTENT
};

/**
 * Result of solving a linear system.
 */
struct SolveResult {
    SolveStatus status;
    vector<double> solution; // valid only if status == UNIQUE
};

/**
 * Solves the linear system Ax = b using Gaussian elimination
 * with partial pivoting.
 *
 * @param A Coefficient matrix (n x n)
 * @param b Right-hand side vector (n)
 * @return SolveResult describing solution type and values if unique
 *
 */
SolveResult solve_linear_system(
    vector<vector<double>> A,
    vector<double> b
) {
    int n = A.size();

    // Build augmented matrix
    vector<vector<double>> M(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            M[i][j] = A[i][j];
        M[i][n] = b[i];
    }

    int pivot_row = 0;

    // Forward elimination
    for (int col = 0; col < n && pivot_row < n; col++) {
        int best = pivot_row;
        for (int r = pivot_row; r < n; r++) {
            if (fabs(M[r][col]) > fabs(M[best][col]))
                best = r;
        }

        if (fabs(M[best][col]) < EPS)
            continue;

        swap(M[pivot_row], M[best]);

        double pivot = M[pivot_row][col];
        for (int c = col; c <= n; c++)
            M[pivot_row][c] /= pivot;

        for (int r = pivot_row + 1; r < n; r++) {
            double factor = M[r][col];
            for (int c = col; c <= n; c++)
                M[r][c] -= factor * M[pivot_row][c];
        }

        pivot_row++;
    }

    // Check inconsistency
    for (int i = 0; i < n; i++) {
        bool zero_row = true;
        for (int j = 0; j < n; j++) {
            if (fabs(M[i][j]) > EPS) {
                zero_row = false;
                break;
            }
        }
        if (zero_row && fabs(M[i][n]) > EPS)
            return {SolveStatus::INCONSISTENT, {}};
    }

    // Check multiple solutions
    if (pivot_row < n)
        return {SolveStatus::MULTIPLE, {}};

    // Back substitution
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = M[i][n];
        for (int j = i + 1; j < n; j++)
            x[i] -= M[i][j] * x[j];
    }

    return {SolveStatus::UNIQUE, x};
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) 
            break;

        vector<vector<double>> A(n, vector<double>(n));
        vector<double> b(n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> A[i][j];

        for (int i = 0; i < n; ++i)
            cin >> b[i];

        SolveResult result = solve_linear_system(A, b);

        if (result.status == SolveStatus::INCONSISTENT) {
            cout << "inconsistent" << endl;
        } 
        else if (result.status == SolveStatus::MULTIPLE) {
            cout << "multiple" << endl;
        } 
        else {
            cout << fixed << setprecision(3);
            for (int i = 0; i < n; ++i) {
                if (i) 
                    cout << " ";
                double v = (fabs(result.solution[i]) < 5e-13) ? 0.0 : result.solution[i];
                cout << v;
            }
            cout << endl;
        }
    }
}