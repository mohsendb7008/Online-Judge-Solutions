n = int(input())
for _ in range(n):
    line = input()
    if line.find(':=') != -1:
        exec(line.replace(':=', '='))
    else:
        exec(f'print({line.split()[1]})')