# Ball Colors

fact = [1]

if __name__ == '__main__':
    for i in range(1, 2502):
        fact.append(i * fact[i-1])
    balls = list(map(int, input().split()))[1:]
    c = list(map(int, input().split()))[1:]
    s = list(map(int, input().split()))[1:]
    bad = 0
    for i in c:
        bad += balls[i-1]
    seq = 51
    for i in s:
        seq = min(seq, balls[i-1])
    if seq < 51:
        for i in s:
            balls[i-1] -= seq
        balls.append(seq)
    ans = 0
    if bad < 2:
        ans = fact[sum(balls)]
    else:
        good = 0
        for i in range(len(balls)):
            if i+1 not in c:
                good += balls[i]
        if good >= bad-1:
            ans = (fact[good] * fact[good+1]) // fact[good-bad+1]
    for r in balls:
        ans //= fact[r]
    print(ans % 1000000007)
    

