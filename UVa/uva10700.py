# Camel trading
if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        s = input()
        g = '*'.join(['('+_+')' for _ in s.split('*')])
        print('The maximum and minimum are %d and %d.' %(eval(g), eval(s)))