wd = []
dir = ''
mem = {}

while True:
    try:
        args = input().split()
        if args[0] == '$':
            if args[1] == 'cd':
                if args[2] == '/':
                    wd.clear()
                elif args[2] == '..':
                    wd.pop()
                else:
                    wd.append(args[2])
            elif args[1] == 'ls':
                dir = '/'.join(wd)
        else:
            if dir not in mem:
                mem[dir] = [0, []]
            if args[0] == 'dir':
                mem[dir][1].append(args[1])
            else:
                mem[dir][0] += int(args[0])
    except EOFError:
        break

dp = {}

def cdp(path):
    if path in dp:
        return dp[path]
    res = mem[path][0]
    for sub in mem[path][1]:
        if path == '':
            res += cdp(sub)
        else:
            res += cdp(path + '/' + sub)
    dp[path] = res
    return res

ans = 0
for path in mem.keys():
    tot = cdp(path)
    if tot <= 100000:
        ans += tot
print(ans)