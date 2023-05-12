ans = 0
while True:
    try:
        line = input()
        s1 = set(line[:len(line)//2])
        s2 = set(line[len(line)//2:])
        s3 = list(s1 & s2)
        if ord(s3[0]) >= ord('a') and ord(s3[0]) <= ord('z'):
            ans += ord(s3[0]) - ord('a') + 1
        if ord(s3[0]) >= ord('A') and ord(s3[0]) <= ord('Z'):
            ans += ord(s3[0]) - ord('A') + 27
    except EOFError:
        break
print(ans)