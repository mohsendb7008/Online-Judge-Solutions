/*
* Authors:
*  - Mohsen Dehbashi
*  - Ghazal Rabiei Faradonbeh
*
* Sieve of Eratosthenes for fast primarily tests
*/

#include <vector>

class PrimeSieve {
    std::vector<bool> is_prime;
    std::vector<size_t> primes;
    bool generatePrimes;
    size_t numPrimes;

public:
    /*
     * Constructs sieve up to n
     * Time complexity: O(n log log n)
     * Space complexity: O(n)
     */
    explicit PrimeSieve(const size_t n, const bool generatePrimes = true) : is_prime(n + 1, true),
        generatePrimes(generatePrimes), numPrimes(0) {

        is_prime[0] = false;
        if (n >= 1) is_prime[1] = false;

        for (size_t p = 2; p <= n; p++) {
            if (is_prime[p]) {
                if (generatePrimes)
                    primes.push_back(p);
                numPrimes++;

                for (size_t q = p * p; q <= n; q += p) {
                    is_prime[q] = false;
                }
            }
        }
    }

    /*
     * Returns true if x is prime
     * O(1) for x <= n
     * O(min(number of primes <= n, sqrt(x))) otherwise
     */
    bool isPrime(const size_t x) const {
        if (x < is_prime.size())
            return is_prime[x];

        for (const size_t p : primes) {
            if (p * p > x)
                break;
            if (x % p == 0)
                return false;
        }
        return true;
    }

    /*
     * Returns number of primes <= n
     * O(1)
     */
    size_t countPrimes() const {
        return numPrimes;
    }
};
