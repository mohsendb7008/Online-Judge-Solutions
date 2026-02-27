#include <vector>

/**
 * Graph V3:
 * - Matrix
 * - Floyd Warshall
 *
 * Authors:
 * - Mohsen Dehbashi
 * - Ghazal Rabiei
 */

/**
 * Directed weighted graph using 2D matrix.
 */
template<typename T>
class GraphV3 {
    std::vector<std::vector<T>> _matrix;
    std::vector<std::vector<size_t>> _trace;
    T _minValue; // -inf (for negative cycles)
    T _maxValue; // inf

public:
    explicit GraphV3(const size_t size, T minValue, T maxValue): _minValue(minValue), _maxValue(maxValue) {
        _matrix.assign(size, std::vector<T>(size, maxValue)); // maxValue = unreachable
        _trace.assign(size, std::vector<size_t>(size, size)); // size = no predecessor
    }

    void addEdge(size_t u, size_t v, T weight) {
        if (weight < _matrix[u][v]) {
            _matrix[u][v] = weight;
        }
    }

    /**
     * Time Complexity: O(V ^ 3)
     * Space Complexity: O(V ^ 2)
     */
    void floyd(T initialValue) {
        // Initiate:
        for (size_t i = 0; i < _matrix.size(); i++) {
            if (initialValue < _matrix[i][i]) {
                _matrix[i][i] = initialValue;
            }
        }
        // Relax:
        for (size_t k = 0; k < _matrix.size(); k++) {
            for (size_t i = 0; i < _matrix.size(); i++) {
                for (size_t j = 0; j < _matrix.size(); j++) {
                    if (_matrix[i][k] < _maxValue && _matrix[k][j] < _maxValue) {
                        if (_matrix[i][k] + _matrix[k][j] < _matrix[i][j]) {
                            _matrix[i][j] = _matrix[i][k] + _matrix[k][j];
                            _trace[i][j] = k;
                        }
                    }
                }
            }
        }
        // Detect negative cycles:
        for (size_t i = 0; i < _matrix.size(); i++) {
            for (size_t j = 0; j < _matrix.size(); j++) {
                for (size_t k = 0; k < _matrix.size(); k++) {
                    if (_matrix[i][k] < _maxValue && _matrix[k][j] < _maxValue && _matrix[k][k] < initialValue) {
                        _matrix[i][j] = _minValue; // there is a negative cycle from i -> j
                    }
                }
            }
        }
    }

    T getMinDistance(size_t u, size_t v) {
        return _matrix[u][v];
    }

    void fillMinPath(const size_t u, const size_t v, std::vector<size_t>& path) {
        const size_t k = _trace[u][v];
        if (k == _trace.size()) { // no predecessor
            path.push_back(u);
        }
        else {
            fillMinPath(u, k, path);
            fillMinPath(k, v, path);
        }
    }
};