if __name__ == '__main__':
    new_cases, new_hospitalizations = int(input()), int(input())
    if new_cases <= 50 and new_hospitalizations <= 10:
        print('White')
    elif new_hospitalizations > 30:
        print('Red')
    else:
        print('Yellow')