# Birthday Memorization

if __name__ == '__main__':
    n = int(input())
    data = dict()
    for i in range(n):
        name, c, d = input().split()
        if d not in data:
            data[d] = (int(c), name)
        elif int(c) > data[d][0]:
            data[d] = (int(c), name)
    ans = list(map(lambda x: x[1], data.values()))
    ans.sort()
    print(len(ans))
    for name in ans:
        print(name)