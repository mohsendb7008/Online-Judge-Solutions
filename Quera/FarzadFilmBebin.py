print('\n'.join(map(lambda x: ' '.join(map(lambda x: x[0].upper()+x[1:].lower(), x)), [input().split() for i in range(int(input()))])))