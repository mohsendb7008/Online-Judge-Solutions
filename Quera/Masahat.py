import math

def each_func(name):
    if name == 'square':
        return lambda a: a ** 2
    if name == 'circle':
        return lambda r: math.pi * r ** 2
    if name == 'rectangle':
        return lambda a, b: a * b
    if name == 'triangle':
        return lambda h, b: h * b / 2

def get_func(ls):
    return list(map(lambda x: each_func(x), ls))

if __name__ == '__main__':
    ls = get_func(['square', 'circle', 'rectangle', 'triangle'])
    print(ls[0](1))
    print(ls[1](2))
    print(ls[2](2, 4))
    print(ls[3](4, 5))