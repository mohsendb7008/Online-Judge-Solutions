from datetime import date
print(x if (x:=(date(*map(int, input().split('-')))-date(1999, 1, 14)).days) >= 0 else 'Not yet born')