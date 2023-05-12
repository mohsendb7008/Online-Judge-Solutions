class Monkey:

    all = {}

    def __init__(self, id, l, op, div, tt, tf):
        Monkey.all[id] = self
        self.id = id
        self.l = l
        self.op = op
        self.div = div
        self.tt = tt
        self.tf = tf

#Monkey(0, [79, 98], 'old * 19', 23, 2, 3)
#Monkey(1, [54, 65, 75, 74], 'old + 6', 19, 2, 0)
#Monkey(2, [79, 60, 97], 'old * old', 13, 1, 3)
#Monkey(3, [74], 'old + 3', 17, 0, 1)

Monkey(0, [98, 89, 52], 'old * 2', 5, 6, 1)
Monkey(1, [57, 95, 80, 92, 57, 78], 'old * 13', 2, 2, 6)
Monkey(2, [82, 74, 97, 75, 51, 92, 83], 'old + 5', 19, 7, 5)
Monkey(3, [97, 88, 51, 68, 76], 'old + 6', 7, 0, 4)
Monkey(4, [63], 'old + 1', 17, 0, 1)
Monkey(5, [94, 91, 51, 63], 'old + 4', 13, 4, 3)
Monkey(6, [61, 54, 94, 71, 74, 68, 98, 83], 'old + 2', 3, 2, 7)
Monkey(7, [90, 56], 'old * old', 11, 3, 5)

inspections = {}

for id in Monkey.all.keys():
    inspections[id] = 0

for _ in range(20):
    for id, monkey in Monkey.all.items():
        inspections[id] += len(monkey.l)
        while monkey.l:
            item = monkey.l.pop(0)
            new = eval(monkey.op.replace('old', str(item)))
            new = new // 3
            if new % monkey.div == 0:
                Monkey.all[monkey.tt].l.append(new)
            else:
                Monkey.all[monkey.tf].l.append(new)

ans = list(inspections.values())
ans.sort()
print(ans[-1] * ans[-2])