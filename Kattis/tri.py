# Tri

if __name__ == "__main__":
    a, b, c = map(int, input().split())
    for op in ["+", "-", "//", "*"]:
        exp = "%d%s%d==%d" %(a, op, b, c)
        if eval(exp):
            print(exp.replace("==", "=").replace("//", "/"))
            break
        exp = "%d==%d%s%d" %(a, b, op, c)
        if eval(exp):
            print(exp.replace("==", "=").replace("//", "/"))
            break
