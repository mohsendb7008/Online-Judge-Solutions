# Babelfish

if __name__ == '__main__':
    out_mode = False
    dic = {}
    while True:
        try:
            line = input()
            if line.strip() == '':
                out_mode = True
                continue
            if out_mode:
                print(dic.get(line, 'eh'))
            else:
                a, b = line.split()
                dic[b] = a
        except EOFError:
            break