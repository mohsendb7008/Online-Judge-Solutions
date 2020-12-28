# Eligibility

if __name__ == '__main__':
    n = int(input())
    for i in range(n):
        name, x, y, z = input().split()
        print(name, end=' ')
        if int(x[:4]) >= 2010:
            print('eligible')
        elif int(y[:4]) >= 1991:
            print('eligible')
        elif int(z) >= 41:
            print('ineligible')
        else:
            print('coach petitions')