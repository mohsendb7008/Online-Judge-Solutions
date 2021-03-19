# Arrangement
n, m = int(input()), int(input())
print('\n'.join(['*' * (m//n) + ('*' if i < m%n else '') for i in range(n)]))