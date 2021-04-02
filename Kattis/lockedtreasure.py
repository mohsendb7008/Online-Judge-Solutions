# Locked Treasure

def fact(n):
    if n < 2:
        return 1
    return n * fact(n - 1)

def c(n, k):
    return fact(n) // (fact(k) * fact(n - k)) 

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n, m = map(int, input().split())
        print(c(n, m-1))