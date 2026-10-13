s = input().lower()

mapping = str.maketrans({
    'á': 'a', 'é': 'e', 'í': 'i',
    'ó': 'o', 'ú': 'u', 'ý': 'y',
    'ö': 'o', 'æ': 'ae', 'ð': 'd', 'þ': 'th'
})

s = s.translate(mapping)
s = ''.join(c for c in s if c.isascii() and c.isalnum())

print(s + '.is')