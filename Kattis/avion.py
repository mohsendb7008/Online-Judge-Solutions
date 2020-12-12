# Avion

if __name__ == '__main__':
    ans = []
    for i in range(5):
        if input().find('FBI') != -1:
            ans.append(str(i + 1))
    print(' '.join(ans) if ans else 'HE GOT AWAY!')
