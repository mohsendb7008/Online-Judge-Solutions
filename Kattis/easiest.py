# The Easiest Problem Is This One

def digitsum(x: int):
    sum = 0
    for c in str(x):
        sum += int(c)
    return sum

if __name__ == "__main__":
    while True:
        n = int(input())
        if n == 0:
            break
        for p in range(11, 101):
            if digitsum(n) == digitsum(n * p):
                print(p)
                break