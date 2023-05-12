elf = 0
ans = 0
while True:
    try:
        e = input()
        if e == '':
            ans = max(ans, elf)
            elf = 0
            continue
        elf += int(e)
    except EOFError:
        break
ans = max(ans, elf)
print(ans)