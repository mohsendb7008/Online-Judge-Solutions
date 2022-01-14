# Functional Fun

if __name__ == '__main__':
    while True:
        try:
            domain = {key: 0 for key in input().split()[1:]}
            codomain = {key: 0 for key in input().split()[1:]}
            for _ in range(int(input())):
                x, _, y = input().split()
                domain[x] += 1
                codomain[y] += 1
            if list(filter(lambda x: x > 1, domain.values())):
                print('not a function')
            else:
                surjective = len(list(filter(lambda x: x < 1, codomain.values()))) == 0
                injective = len(list(filter(lambda x: x > 1, codomain.values()))) == 0
                if surjective and injective:
                    print('bijective')
                elif surjective:
                    print('surjective')
                elif injective:
                    print('injective')
                else:
                    print('neither injective nor surjective')
        except EOFError:
            break