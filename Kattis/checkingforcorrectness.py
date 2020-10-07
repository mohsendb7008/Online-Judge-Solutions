# Checking For Correctness

def fastpow(a, b):
    if b == 1:
        return a % 10000
    elif b % 2 == 1:
        tmp = fastpow(a, b - 1)
        return ((a % 10000) * tmp) % 10000
    tmp = fastpow(a, b / 2)
    return (tmp * tmp) % 10000 
    
if __name__ == "__main__":
    try:
        while True:
            a, b, c = input().split()
            if b == '+':
                print((int(a) + int(c)) % 10000)
            elif b == '*':
                print((int(a) * int(c)) % 10000)
            else:
                print(fastpow(int(a), int(c)))
    except:
        pass