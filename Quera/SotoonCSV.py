def process(path):
    rows = list(map(lambda row: list(map(lambda num: int(num.strip()), row.split(','))), open(path).readlines()))
    for row in rows:
        row.append(sum(row))
    with open('ans.csv', 'w') as f:
        for row in rows:
            f.write(f"{', '.join(map(str, row))}\n")