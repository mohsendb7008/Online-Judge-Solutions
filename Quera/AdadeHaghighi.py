import re

real_number = re.compile('[+-]?[\d]+(.[\d]+)?([Ee][+-]?[\d]+)?\n')

if __name__ == '__main__':
    while True:
        try:
            print('LEGAL' if real_number.match(input().strip()+'\n') else 'ILLEGAL')
        except EOFError:
            break