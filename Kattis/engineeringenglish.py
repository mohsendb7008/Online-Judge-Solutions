# Engineering English

if __name__ == '__main__':
    eff = {}
    def f(word):
        ret = eff.get(word.lower(), word)
        eff[word.lower()] = '.'
        return ret
    while True:
        try:
            print(' '.join(map(f, input().split())))
        except EOFError:
            break
