from math import fabs


class GaussianSolver:
    """
    Linear equations system solver using Gaussian Elimination method
    """

    EPS = 1e-9

    def __init__(self, augmented_matrix):
        """
        :param augmented_matrix: coefficients matrix + constants vector
        usage example:
        >>> solver = GaussianSolver([
        >>>    [1, -1, -1, 1, 0],
        >>>    [2, 0, 2, 0, 8],
        >>>    [0, -1, -2, 0, -8],
        >>>    [3, -3, -2, 4, 7]
        >>> ])
        """
        self.augmented_matrix = augmented_matrix

    def solve(self):
        """
        :returns: None if there is no unique answer for system otherwise answers vector
        usage example:
        >>> solver.solve()
        >>> [1.0, 2.0, 3.0, 4.0]
        """
        n = len(self.augmented_matrix)
        # Making the augmented matrix upper triangular:
        for i in range(n):
            # Finding a non-zero pivot:
            if fabs(self.augmented_matrix[i][i]) < GaussianSolver.EPS:
                exchange_row = i
                for j in range(i+1, n):
                    if not fabs(self.augmented_matrix[j][i]) < GaussianSolver.EPS:
                        exchange_row = j
                        break
                if exchange_row == i:
                    return None
                self.augmented_matrix[i], self.augmented_matrix[exchange_row] = self.augmented_matrix[exchange_row], self.augmented_matrix[i]
            # Eliminating:
            for j in range(i+1, n):
                if fabs(self.augmented_matrix[j][i]) < GaussianSolver.EPS:
                    continue
                multiplier = -self.augmented_matrix[j][i] / self.augmented_matrix[i][i]
                for k in range(i, n+1):
                    self.augmented_matrix[j][k] += multiplier * self.augmented_matrix[i][k]
        # Back-substitution:
        answer_vector = []
        for i in range(n-1, -1, -1):
            answer = self.augmented_matrix[i][n]
            for j in range(i+1, n):
                answer -= self.augmented_matrix[i][j] * answer_vector[n-1-j]
            answer_vector.append(answer / self.augmented_matrix[i][i])
        answer_vector.reverse()
        return answer_vector


if __name__ == '__main__':
    solver = GaussianSolver([
        [1, -1, -1, 1, 0],
        [2, 0, 2, 0, 8],
        [0, -1, -2, 0, -8],
        [3, -3, -2, 4, 7]
    ])
    print(solver.solve())
