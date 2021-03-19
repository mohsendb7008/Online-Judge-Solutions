from math import fabs

# 3-Sided Dice


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
    while True:
        try:
            a1, b1, c1 = map(int, input().split())
            a2, b2, c2 = map(int, input().split())
            a3, b3, c3 = map(int, input().split())
            a4, b4, c4 = map(int, input().split())
            input()
            solution = GaussianSolver([[a1, a2, a3, a4], [b1, b2, b3, b4], [c1, c2, c3, c4]]).solve()
            if solution:
                ok = True
                for i in range(3):
                    if fabs(solution[i]) < GaussianSolver.EPS or solution[i] <= 0 or solution[i] > 1 + GaussianSolver.EPS:
                        ok = False
                        break
                if not fabs(sum(solution) - 1.0) < GaussianSolver.EPS:
                    ok = False
                print('YES' if ok else 'NO')
            else:
                print('NO')
        except EOFError:
            break
