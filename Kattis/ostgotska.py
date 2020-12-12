# Ostgotska
if __name__ == '__main__':
    words = input().split()
    cnt = 0
    for word in words:
        if word.find('ae') != -1:
            cnt += 1
    print('dae ae ju traeligt va' if 10 * cnt >= 4 * len(words)  else 'haer talar vi rikssvenska')
