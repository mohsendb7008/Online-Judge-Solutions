# Simon Says
n = int(input())
for i in range(n):
    inp = input()
    if inp.startswith('Simon says'):
        print(inp[11:])
