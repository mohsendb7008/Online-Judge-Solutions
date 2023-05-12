def compare(left, right):
    if type(left) == int and type(right) == int:
        if left < right:
            return 1
        if left > right:
            return -1
        return 0
    if type(left) == int:
        return compare([left], right)
    if type(right) == int:
        return compare(left, [right])
    if not left and not right:
        return 0
    if not left:
        return 1
    if not right:
        return -1
    c = compare(left[0], right[0])
    if c != 0:
        return c
    return compare(left[1:], right[1:])

if __name__ == '__main__':
    index = 0
    ans = 0
    while True:
        left = eval(input())
        right = eval(input())
        eof = input()
        index += 1
        comp = compare(left, right)
        assert comp != 0
        if comp == 1:
            ans += index
        if eof == "EOF":
            break
    print(ans)