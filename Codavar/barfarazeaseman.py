# Bar Faraze Aseman

ca, m, f = {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0,
            8: 0, 9: 0, 10: 0, 11: 0, 12: 0}, {}, {}


if __name__ == "__main__":
    k, n, m_ = map(int, input().split())
    for _ in range(m_):
        u, v, d, c = map(int, input().split())
        f[(u, v, d)] = c
    for _ in range(k*n):
        a, b, c = map(int, input().split())
        m[(a, b)] = c
    for day in range(1, n+1):
        for airport in range(1, k+1):
            ca[airport] += m[(airport, day)]
        ca2 = {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0,
               8: 0, 9: 0, 10: 0, 11: 0, 12: 0}
        for airport in range(1, k+1):
            for airport2 in range(1, k+1):
                if (airport, airport2, day) in f:
                    flight = f[(airport, airport2, day)]
                    if ca[airport] < flight:
                        print("suboptimal")
                        exit(0)
                    ca[airport] -= flight
                    ca2[airport2] += flight
        for i in range(1, 13):
            ca[i] += ca2[i]
    print("optimal")
