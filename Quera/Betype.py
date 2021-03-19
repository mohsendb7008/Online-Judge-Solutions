s, l = input(), []
for c in s:
    if c == '=':
        if l:
            l.pop()
    else:
        l.append(c)
print(''.join(l))