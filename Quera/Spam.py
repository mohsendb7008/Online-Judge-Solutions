import re
s, m = input(), input()
ans = 0
if s.isdigit():
    ans += 1
if re.findall('[sS][pP][aA][mM]', m) and sum(list(map(lambda x: len(x), re.split('[\w\s]*', m)))) > len(m) // 2:
    ans += 2
if ans == 0:
    print('Not Spam')
elif ans == 1:
    print('Invalid Sender')
elif ans == 2:
    print('Invalid Content')
else:
    print('Fully Invalid')