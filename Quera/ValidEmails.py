aldi = set("abcdefghijklmnopqrstuvwxyz0123456789")

def check_part(s: str, c: str):
    for a in s:
        assert a in aldi or a == c

def check_username(s: str):
    assert s != ''
    parts = s.split('.')
    for part in parts:
        assert part != ''
        check_part(part, '_')
    ans = ''.join(parts)
    assert 6 <= len(ans) <= 30
    return ans
    
def check_domain(s: str):
    assert s != ''
    parts = s.split('.')
    for part in parts:
        assert part != ''
        check_part(part, '-')
    assert 3 <= len(s) <= 30
    return s

def process(s: str):
    l = s.split('@')
    assert len(l) == 2
    username = check_username(l[0])
    domain = check_domain(l[1])
    return f'{username}@{domain}'


if __name__ == "__main__":
    n = int(input())
    ans = set()
    for i in range(n):
        try:
            ans.add(process(input().lower()))
        except AssertionError:
            pass
    print(len(ans))
