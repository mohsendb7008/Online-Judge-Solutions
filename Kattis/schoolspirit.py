# School Spirit

def score(a):
    ans = 0
    for i in range(len(a)):
        ans += a[i] * (4 / 5) ** i
    return ans / 5

if __name__ == '__main__':
    n = int(input())
    s = [int(input()) for _ in range(n)]
    print(score(s))
    avg = 0
    for i in range(n):
        save = s.pop(i)
        avg += score(s)
        s.insert(i, save)
    print(avg / n)
