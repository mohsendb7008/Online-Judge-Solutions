# Soda Slurper

if __name__ == "__main__":
    e, f, c = map(int, input().split())
    e += f
    soda = 0
    while e >= c:
        soda += e // c
        e = e // c + e % c
    print(soda)
