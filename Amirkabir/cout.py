import re

integer = re.compile(r'\d+')
accepted_c = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-_ <"'
accepted_c = set([i for i in accepted_c])

if __name__ == '__main__':
    ans = []
    try:
        cmd = input().strip()
        size_ = len(cmd)
        assert cmd[size_ - 1] == ';'
        for c in cmd[:-1]:
            assert c in accepted_c
        tokens = cmd[:-1].split('<<')
        assert len(tokens) > 1
        assert tokens[0].strip() == 'cout'
        tokens = tokens[1:]
        for token in tokens:
            t = token.strip()
            assert t != ''
            if t == 'endl':
                ans.append('\n')
                continue
            if integer.match(t):
                assert int(t) > 0
                ans.append(int(t))
                continue
            tt = t.split('"')
            assert len(tt) == 3
            assert tt[0].strip() == ''
            assert tt[2].strip() == ''
            ans.append(tt[1])
    except AssertionError:
        print('ERROR')
        exit(0)
    except ValueError:
        print('ERROR')
        exit(0)
    except IndexError:
        print('ERROR')
        exit(0)
    for a in ans:
        print(a, end='')