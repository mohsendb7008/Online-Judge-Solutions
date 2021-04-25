import re

class Security:

    def secure(self, info):
        l = info.split()
        ans = []
        for part in l:
            if self.is_social_account_info(part):
                parts = part.split('/')
                ans.append(parts[0] + '/' + self.encrypt(parts[1]))
            else:
                ans.append(part)
        return ' '.join(ans)

    def is_social_account_info(self, param):
        l = re.findall('[A-Z][\w]*:www\.[a-z\d\.]+/[\w_]+', param)
        if l and l[0] == param:
            return True
        return False

    def weight(self, c, n):
        ans = ''
        for i in range(n):
            ans += str((ord(c) - 96) * (i + 1))
        return ans
    
    def encrypt(self, s):
        if not s:
            return ''
        last = s[0]
        cnt = 1
        ans = ''
        for i in range(1, len(s)):
            if s[i] == last:
                cnt += 1
            else:
                ans += self.weight(last, cnt)
                last = s[i]
                cnt = 1
        ans += self.weight(last, cnt)
        return ans

if __name__ == '__main__':
    sec = Security()
    print(sec.weight('c', 4))
    print(sec.encrypt('abcccdd'))
    print(sec.is_social_account_info('Twitter:www.twitter.com/javalover1990'))
    print(sec.is_social_account_info('Instagram:www.instagram.com/javafan'))
    print(sec.secure('FirstName:Ali, LastName:Alavi, BirthDate:1990/02/02 Gender:male Instagram:www.instagram.com/aalavi Degree:Master Twitter:www.twiter.com/alaviii imdb:www.imdb.com/alavi'))