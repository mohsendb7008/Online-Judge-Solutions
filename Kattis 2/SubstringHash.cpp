#include <string>
#include "../Math/NumberTheory.cpp"

template <typename T = long>
class SubstringHash {
    std::string str{};
    T p;
    NumberTheory::ModularArithmetic<T> ma;
    std::vector<T> prefixHash{};
    std::vector<T> pInverse{};

public:
    explicit SubstringHash(const std::string &str, T p, T mod, T base) : str(str), p(p), ma(mod) {
        size_t n = str.size();

        prefixHash.reserve(n);
        prefixHash.push_back(str[0] - base);
        T pn = p;
        for (size_t i = 1; i < n; i++) {
            prefixHash.push_back(ma.add(prefixHash.back(), ma.mul(str[i] - base, pn)));
            pn = ma.mul(pn, p);
        }

        pInverse.reserve(n);
        pInverse.push_back(1);
        T pi = ma.inverse(p);
        for (size_t i = 1; i < n; i++) {
            pInverse.push_back(ma.mul(pInverse.back(), pi));
        }
    }

    T getHash(size_t l, size_t r) {
        T diff = ma.sub(prefixHash[r], l ? prefixHash[l - 1] : 0);
        return ma.mul(diff, pInverse[l]);
    }
};