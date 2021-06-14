from datetime import datetime

weekdays = {
    'Monday': 0,
    'Tuesday': 1,
    'Wednesday': 2,
    'Thursday': 3,
    'Friday': 4,
    'Saturday': 5,
    'Sunday': 6
}

schedule = [[], [], [], [], [], [], []]
excepts = {
    'Station': [],
    'Store': [],
    'Tenant': []
}

if __name__ == '__main__':
    n, m, q = map(int, input().split())
    for _ in range(n):
        day, st, en = input().split()
        tst = datetime.strptime(st, '%H:%M')
        st = tst.hour * 60 + tst.minute
        ten = datetime.strptime(en, '%H:%M')
        en = ten.hour * 60 + ten.minute
        schedule[weekdays[day]].append((st, en))
    for _ in range(m):
        exc, st, en, status = input().split()
        st = datetime.strptime(st, '%Y-%m-%dT%H:%M')
        en = datetime.strptime(en, '%Y-%m-%dT%H:%M')
        excepts[exc].append((st, en, status))
    for _ in range(q):
        d = datetime.strptime(input(), '%Y-%m-%dT%H:%M')
        found = False
        for _, except_list in excepts.items():
            for excs in except_list:
                if excs[0] <= d <= excs[1]:
                    if excs[2] == 'open':
                        print('true')
                    elif excs[2] == 'closed':
                        print('false')
                    found = True
                    break
            if found:
                break
        if found:
            continue
        for ts in schedule[d.weekday()]:
            if ts[0] <= d.hour * 60 + d.minute <= ts[1]:
                print('true')
                found = True
                break
        if not found:
            print('false')