score = {
    'X': 1, # Rock A
    'Y': 2, # Paper B
    'Z': 3 # Sci C
}

game = {
    'X':
        {
            'A': 3,
            'B': 0,
            'C': 6
        }
    ,
    'Y':{
            'A': 6,
            'B': 3,
            'C': 0
        }
    ,
    'Z':
        {
            'A': 0,
            'B': 6,
            'C': 3
        }
}

ans = 0
while True:
    try:
        a, b = input().split()
        ans += score[b] + game[b][a]
    except EOFError:
        break
print(ans)

