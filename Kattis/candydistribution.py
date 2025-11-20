import sys
import threading

def solve():
    import sys
    input=sys.stdin.readline
    t=int(input())
    for _ in range(t):
        K,C=map(int,input().split())
        if C==1:
            if K+1<=10**9:
                print(K+1)
            else:
                print("IMPOSSIBLE")
            continue
        if K==1:
            print(1)
            continue
        a=C
        m=K
        def egcd(a,b):
            if b==0:
                return (1,0,a)
            x,y,g=egcd(b,a%b)
            return (y, x-(a//b)*y, g)
        x,y,g=egcd(a,m)
        if g!=1:
            print("IMPOSSIBLE")
            continue
        x=x%(m)
        if x<=10**9:
            print(x)
        else:
            print("IMPOSSIBLE")

if __name__=="__main__":
    threading.Thread(target=solve).start()
