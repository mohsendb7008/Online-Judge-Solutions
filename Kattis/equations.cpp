#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <vector>
#include <cmath>
using namespace std;

vector<string> split(const string& str, const char delim){
    vector<string> cont;
    stringstream ss(str);
    string token;
    while(getline(ss, token, delim))
        cont.push_back(token);
    return cont;
}

/**
 * Template structure representing a mathematical fraction.
 *
 * API:
 *  fraction()                     -> Creates 0/1.
 *  fraction(T num, T denom)       -> Creates a reduced fraction.
 *  operator+, -, *, /            -> Arithmetic operations.
 *  operator<, ==                 -> Comparisons.
 *  negate()                      -> Returns the negated fraction.
 *  reverse()                     -> Returns the reciprocal.
 */
template<typename T>
struct fraction {
    T numerator, denominator;
    double real;

    T GCD(const T a, const T b) {
        if (a == 0)
            return b;
        return GCD(b % a, a);
    }

    /// Default constructor: initializes fraction to 0/1.
    fraction() {
        numerator = 0;
        denominator = 1;
        real = 0.0;
    }

    /**
     * Constructs a fraction and reduces it.
     */
    fraction(T numerator, T denominator) {
        if (denominator == 0) {
            this->numerator = numeric_limits<T>::max();
            this->denominator = 1;
        }
        else if (numerator == 0) {
            this->numerator = 0;
            this->denominator = 1;
        }
        else {
            // Normalize sign so denominator is always positive
            T sign = (numerator > 0 ? 1 : -1) * (denominator > 0 ? 1 : -1);
            numerator = abs(numerator);
            denominator = abs(denominator);

            T gcd = GCD(min(numerator, denominator), max(numerator, denominator));
            this->numerator = sign * numerator / gcd;
            this->denominator = denominator / gcd;
        }

        real = static_cast<double>(this->numerator) / this->denominator;
    }

    fraction &operator=(const fraction &other) = default;

    /**
     * Less-than comparison.
     */
    bool operator<(const fraction &other) const {
        if (numerator == numeric_limits<T>::max())
            return false;
        if (other.numerator == numeric_limits<T>::max())
            return true;
        return numerator * other.denominator < other.numerator * denominator;
    }

    /// Equality comparison.
    bool operator==(const fraction &other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    /// Returns the negated fraction.
    fraction negate() {
        if (numerator == numeric_limits<T>::max())
            return fraction(1, 0);
        if (numerator == 0)
            return fraction(0, 1);
        return fraction(-numerator, denominator);
    }

    /// Returns the reciprocal of the fraction.
    fraction reverse() {
        if (numerator == numeric_limits<T>::max())
            return fraction(0, 1);
        if (numerator == 0)
            return fraction(1, 0);
        return fraction(denominator, numerator);
    }

    /// Adds two fractions.
    fraction operator+(const fraction &other) const {
        return fraction(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    /// Subtracts another fraction from this one.
    fraction operator-(const fraction &other) const {
        return fraction(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    /// Multiplies two fractions.
    fraction operator*(const fraction &other) const {
        return fraction(numerator * other.numerator, denominator * other.denominator);
    }

    /**
     * Divides this fraction by another.
     */
    fraction operator/(const fraction &other) const {
        fraction p(numerator, denominator);
        fraction q(other.numerator, other.denominator);
        return p * q.reverse();
    }
};

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
    vector<fraction<int>> values;   // meaningful only when known[i] == true
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
    const vector<vector<fraction<int>>> &A,
    const vector<fraction<int>> &b
) {
    const int n = static_cast<int>(A.size());

    vector<vector<fraction<int>>> M(n, vector<fraction<int>>(n + 1, fraction<int>()));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            M[i][j] = A[i][j];
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
            if (fabs(M[r][col].real) > fabs(M[best][col].real))
                best = r;
        }

        if (fabs(M[best][col].real) < EPS) {
            // No pivot in this column -> free variable column
            continue;
        }

        swap(M[pivot_row], M[best]);

        const fraction<int> pv = M[pivot_row][col];
        for (int c = col; c <= n; c++)
            M[pivot_row][c] = M[pivot_row][c] / pv;

        for (int r = pivot_row + 1; r < n; r++) {
            const fraction<int> factor = M[r][col];
            if (fabs(factor.real) < EPS)
                continue;
            for (int c = col; c <= n; c++)
                M[r][c] = M[r][c] - factor * M[pivot_row][c];
        }

        pivotColOfRow[pivot_row] = col;
        rowOfPivotCol[col] = pivot_row;
        isPivotCol[col] = true;
        pivot_row++;
    }

    for (int i = 0; i < n; i++) {
        bool allZeroLeft = true;
        for (int j = 0; j < n; j++) {
            if (fabs(M[i][j].real) > EPS) {
                allZeroLeft = false;
                break;
            }
        }
        if (allZeroLeft && fabs(M[i][n].real) > EPS) {
            return {SolveStatus::INCONSISTENT, {}, {}};
        }
    }

    // Back elimination (eliminate above pivots)
    for (int r = pivot_row - 1; r >= 0; r--) {
        const int pc = pivotColOfRow[r];
        if (pc < 0)
            continue;

        for (int up = r - 1; up >= 0; up--) {
            const fraction<int> factor = M[up][pc];
            if (fabs(factor.real) < EPS)
                continue;
            for (int c = pc; c <= n; c++)
                M[up][c] = M[up][c] - factor * M[r][c];
        }
    }

    // Determine which variables are uniquely determined
    vector<bool> known(n, false);
    vector<fraction<int>> values(n, fraction<int>());

    for (int var = 0; var < n; var++) {
        if (!isPivotCol[var]) {
            // Free variable -> not uniquely determined
            known[var] = false;
            continue;
        }

        const int r = rowOfPivotCol[var];

        // If pivot row contains any nonzero coefficient in a free column,
        // then this pivot variable depends on free vars -> not unique.
        bool dependsOnFree = false;
        for (int col = 0; col < n; col++) {
            if (!isPivotCol[col] && fabs(M[r][col].real) > EPS) {
                dependsOnFree = true;
                break;
            }
        }

        if (dependsOnFree) {
            known[var] = false;
        } else {
            known[var] = true;
            values[var] = M[r][n];
        }
    }

    return {SolveStatus::CONSISTENT, known, values};
}

vector<vector<fraction<int>>> A(2, vector<fraction<int>>(2, fraction<int>()));
vector<fraction<int>> B(2, fraction<int>());

inline void process(const string& s, const int row) {
    const auto tokens = split(s, ' ');
    int side = 1;
    int sign = 1;
    for (const string& token : tokens) {
        if (token == "=") {
            side = -1;
            sign = 1;
        }
        else if (token == "+") {
            sign = 1;
        }
        else if (token == "-") {
            sign = -1;
        }
        else if (token.back() == 'x') {
            string t = token;
            t.pop_back();
            int number;
            if (t.empty())
                number = 1;
            else if (t == "-")
                number = -1;
            else
                number = atoi(t.c_str());
            number *= sign * side;
            A[row][0] = A[row][0] + fraction<int>(number, 1);
            sign = 1;
        }
        else if (token.back() == 'y') {
            string t = token;
            t.pop_back();
            int number;
            if (t.empty())
                number = 1;
            else if (t == "-")
                number = -1;
            else
                number = atoi(t.c_str());
            number *= sign * side;
            A[row][1] = A[row][1] + fraction<int>(number, 1);
            sign = 1;
        }
        else {
            const int number = sign * side * -1 * atoi(token.c_str());
            B[row] = B[row] + fraction<int>(number, 1);
            sign = 1;
        }
    }
}

int main() {
    int T;
    cin >> T;
    string dummy;
    getline(cin, dummy);
    while (T--) {
        string line1, line2;
        getline(cin, line1);
        getline(cin, line2);
        getline(cin, dummy);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                A[i][j] = fraction<int>();
            }
            B[i] = fraction<int>();
        }
        process(line1, 0);
        process(line2, 1);
        auto solution = solve_linear_system_with_unknowns(A, B);
        if (solution.status == SolveStatus::CONSISTENT && solution.known[0]) {
            cout << solution.values[0].numerator;
            if (solution.values[0].denominator != 1)
                cout << "/" << solution.values[0].denominator;
            cout << endl;
        }
        else cout << "don't know" << endl;
        if (solution.status == SolveStatus::CONSISTENT && solution.known[1]) {
            cout << solution.values[1].numerator;
            if (solution.values[1].denominator != 1)
                cout << "/" << solution.values[1].denominator;
            cout << endl;
        }
        else cout << "don't know" << endl;
        cout << endl;
    }
}