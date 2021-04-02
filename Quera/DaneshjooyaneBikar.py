import re

if __name__ == '__main__':
    A, _, B, _, C = input().split()
    if '#' in A:
        ans = str(int(C) - int(B))
        print(f'{ans} + {B} = {C}' if re.compile(A.replace('#', '[\d]*')+'\n').match(ans+'\n') else -1)
    elif '#' in B:
        ans = str(int(C) - int(A))
        print(f'{A} + {ans} = {C}' if re.compile(B.replace('#', '[\d]*')+'\n').match(ans+'\n') else -1)
    elif '#' in C:
        ans = str(int(A) + int(B))
        print(f'{A} + {B} = {ans}' if re.compile(C.replace('#', '[\d]*')+'\n').match(ans+'\n') else -1)
    else:
        print(f'{A} + {B} = {C}' if int(A) + int(B) == int(C) else -1)