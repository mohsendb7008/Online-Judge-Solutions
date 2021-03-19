n, t = input().split()
n, t = int(n), set(t)
print('\n'.join([('Yes' if set(input()) == t else 'No') for i in range(n)]))