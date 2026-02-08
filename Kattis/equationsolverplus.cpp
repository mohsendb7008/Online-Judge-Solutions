/*
 * Author:
 *      Ghazal Rabiei
 *      Mohsen Dehbashi
 *
 * Gaussian elimination solver for linear systems Ax = b
 *
 * This variant prints each variable's value if it is uniquely determined,
 * otherwise prints "?" for that variable.
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
    CONSISTENT,    // at least one solution exists
    INCONSISTENT
};

/**
 * Result of solving a linear system in the "unknown variables" sense.
 *
 * If status == INCONSISTENT: the system has no solutions.
 * If status == CONSISTENT: values[i] is set when x_i is uniquely determined,
 *                          otherwise values[i] is not meaningful
 *
 */
struct PartialSolveResult {
    SolveStatus status;
    vector<bool> known;      // known[i] == true  => values[i] is uniquely determined
    vector<double> values;   // meaningful only when known[i] == true
};

/**
 * Solves Ax = b and determines which variables are uniquely determined.
 *
 * Approach:
 *  - (forward elimination + back elimination).
 *  - If inconsistent: return INCONSISTENT.
 *  - Let pivot columns be constrained variables; non-pivot columns are free.
 *  - A pivot variable is uniquely determined if its pivot row has zero
 *    coefficients in all free-variable columns.
 */
PartialSolveResult solve_linear_system_with_unknowns(
    vector<vector<double>> A,
    vector<double> b
) {
    int n = (int)A.size();

    vector<vector<double>> M(n, vector<double>(n + 1, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }

    // Pivot bookkeeping
    vector<int> pivotColOfRow(n, -1);
    vector<int> rowOfPivotCol(n, -1);
    vector<bool> isPivotCol(n, false);  // isPivotCol[col] == true if col is a pivot column

    int pivot_row = 0;

    // Forward elimination with partial pivoting
    for (int col = 0; col < n && pivot_row < n; col++) {
        int best = pivot_row;
        for (int r = pivot_row; r < n; r++) {
            if (fabs(M[r][col]) > fabs(M[best][col]))
                best = r;
        }

        if (fabs(M[best][col]) < EPS) {
            // No pivot in this column -> free variable column
            continue;
        }

        swap(M[pivot_row], M[best]);

        double pv = M[pivot_row][col];
        for (int c = col; c <= n; c++)
            M[pivot_row][c] /= pv;

        for (int r = pivot_row + 1; r < n; r++) {
            double factor = M[r][col];
            if (fabs(factor) < EPS) continue;
            for (int c = col; c <= n; c++)
                M[r][c] -= factor * M[pivot_row][c];
        }

        pivotColOfRow[pivot_row] = col;
        rowOfPivotCol[col] = pivot_row;
        isPivotCol[col] = true;
        pivot_row++;
    }

    for (int i = 0; i < n; i++) {
        bool allZeroLeft = true;
        for (int j = 0; j < n; j++) {
            if (fabs(M[i][j]) > EPS) {
                allZeroLeft = false;
                break;
            }
        }
        if (allZeroLeft && fabs(M[i][n]) > EPS) {
            return {SolveStatus::INCONSISTENT, {}, {}};
        }
    }

    // Back elimination (eliminate above pivots)
    for (int r = pivot_row - 1; r >= 0; r--) {
        int pc = pivotColOfRow[r];
        if (pc < 0) continue;

        for (int up = r - 1; up >= 0; up--) {
            double factor = M[up][pc];
            if (fabs(factor) < EPS) continue;
            for (int c = pc; c <= n; c++)
                M[up][c] -= factor * M[r][c];
        }
    }

    // Determine which variables are uniquely determined
    vector<bool> known(n, false);
    vector<double> values(n, 0.0);

    for (int var = 0; var < n; var++) {
        if (!isPivotCol[var]) {
            // Free variable -> not uniquely determined
            known[var] = false;
            continue;
        }

        int r = rowOfPivotCol[var];

        // If pivot row contains any nonzero coefficient in a free column,
        // then this pivot variable depends on free vars -> not unique.
        bool dependsOnFree = false;
        for (int col = 0; col < n; col++) {
            if (!isPivotCol[col] && fabs(M[r][col]) > EPS) {
                dependsOnFree = true;
                break;
            }
        }

        if (dependsOnFree) {
            known[var] = false;
        } else {
            known[var] = true;
            double v = (fabs(M[r][n]) < 5e-13) ? 0.0 : M[r][n]; // avoid -0.00
            values[var] = v;
        }
    }

    return {SolveStatus::CONSISTENT, known, values};
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<vector<double>> A(n, vector<double>(n));
        vector<double> b(n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> A[i][j];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        PartialSolveResult result = solve_linear_system_with_unknowns(A, b);

        if (result.status == SolveStatus::INCONSISTENT) {
            cout << "inconsistent" << endl;
            continue;
        }

        cout << fixed << setprecision(2);
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            if (!result.known[i]) cout << "?";
            else cout << result.values[i];
        }
        cout << endl;
    }
}