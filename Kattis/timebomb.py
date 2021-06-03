# Timebomb

import sys

lines = [
    "***   * *** *** * * *** *** *** *** ***",
    "* *   *   *   * * * *   *     * * * * *",
    "* *   * *** *** *** *** ***   * *** ***",
    "* *   * *     *   *   * * *   * * *   *",
    "***   * *** ***   * *** ***   * *** ***",
]

start_index = [0, 4, 8, 12, 16, 20, 24, 28, 32, 36]

input_lines = []

def check(i, digit):
    for j in range(5):
        for k in range(3):
            if input_lines[j][i+k] != lines[j][4*digit+k]:
                return False
    return True  

if __name__ == '__main__':
    for i in range(5):
        input_lines.append(input())
    n = (len(input_lines[0]) + 1) // 4
    ans = ""
    for i in range(n):
        k = None
        for d in range(10):
            if check(4 * i, d):
                k = str(d)
                break
        if not k:
            print('BOOM!!')
            sys.exit(0)
        ans += k
    print('BEER!!' if int(ans) % 6 == 0 else 'BOOM!!')