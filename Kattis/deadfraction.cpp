#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
using namespace std;

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

#define num long long int

inline fraction<num> getFraction(const num nonRepeating, const num repeating, num a, num b) {
    num nDenominator = 1;
    num rDenominator = 0;
    while (b--) {
        rDenominator = rDenominator * 10 + 9;
    }
    while (a--) {
        nDenominator *= 10;
        rDenominator *= 10;
    }
    return fraction<num>(nonRepeating, nDenominator) +
        fraction<num>(repeating, repeating ? rDenominator : 1);
}

int main () {
    char input[10];
    while (scanf("0.%[^.]...\n", input)) {
        string number = input;
        const int r = static_cast<int>(number.size());
        fraction<num> ans = getFraction(0, stoll(number), 0, r);
        for (int i = 1; i < r; i++) {
            const num nonRepeating = stoll(number.substr(0, i));
            const num repeating = stoll(number.substr(i));
            const fraction<num> candidate = getFraction(nonRepeating, repeating, i, r - i);
            if (candidate.denominator < ans.denominator) {
                ans = candidate;
            }
        }
        printf("%lld/%lld\n", ans.numerator, ans.denominator);
    }
}