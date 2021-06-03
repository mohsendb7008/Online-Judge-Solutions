# Saving For Retirement

if __name__ == '__main__':
    B, Br, Bs, A, As = map(int, input().split())
    income = (Br - B) * Bs
    print(income // As + 1 + A)