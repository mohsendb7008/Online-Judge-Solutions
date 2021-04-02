k, key, ans = int(input()), input(), 0
for i in range(k):
    gear = input()
    place = gear.find(key[i])
    ans += min(place, 9-place)
print(ans)