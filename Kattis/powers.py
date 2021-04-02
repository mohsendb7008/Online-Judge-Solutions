# Powers and Modulus

if __name__ == '__main__':
    a, b = map(int, input().split())
    print(((a // 2) ** b) % a if a % 2 == 0 else 0)