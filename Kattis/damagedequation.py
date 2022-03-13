# Damaged Equation

if __name__ == '__main__':
    a, b, c, d = map(int, input().split())
    ops = ['*', '+', '-', '//']
    ans = []
    for op1 in ops:
        for op2 in ops:
            if (op1 == '//' and b == 0) or (op2 == '//' and d == 0):
                continue
            first = f'{a} {op1} {b}'
            second = f'{c} {op2} {d}'
            if eval(first) == eval(second):
                ans.append(f'{first} = {second}'.replace('//', '/'))
    print('\n'.join(ans) if ans else 'problems ahead')
