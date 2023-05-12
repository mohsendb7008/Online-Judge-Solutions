actual = {}
operational = {}

def calculate(monkey):
    if monkey in actual:
        return actual[monkey]
    op = operational[monkey].split()
    if len(op) == 1:
        actual[monkey] = int(op[0])
        return actual[monkey]
    nop = operational[monkey]
    nop = nop.replace(op[0], str(calculate(op[0])))
    nop = nop.replace(op[2], str(calculate(op[2])))
    nop = nop.replace('/', '//')
    actual[monkey] = eval(nop)
    return actual[monkey]

while True:
    try:
        monkey, op = input().split(": ")
        operational[monkey] = op
    except KeyboardInterrupt:
        break

print(calculate('root'))
 