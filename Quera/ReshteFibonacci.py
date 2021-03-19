n, fib = int(input()), [1, 2]
while fib[-1] < n:
    fib.append(fib[-2]+fib[-1])
print(''.join(map(lambda x: '+' if x in fib else '-', range(1, n+1))))