# Help a PhD candidate out!

if __name__ == '__main__':
    n = int(input())
    for i in range(n):
        s = input()
        if s == 'P=NP':
            print('skipped')
        else:
            print(eval(s))