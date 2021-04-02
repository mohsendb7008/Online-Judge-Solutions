# Tree Insertion

fact = [1]

def count(bst):
    if len(bst) <= 1:
        return 1
    root = bst[0]
    left, right = [], []
    for i in range(1, len(bst)):
        if bst[i] < root:
            left.append(bst[i])
        else:
            right.append(bst[i])
    return count(left) * count(right) * fact[len(bst) - 1] // (fact[len(left)] * fact[len(right)])

if __name__ == '__main__':
    for i in range(1, 101):
        fact.append(fact[i-1] * i)
    while True:
        if int(input()) == 0:
            break
        bst = list(map(int, input().split()))
        print(count(bst))

