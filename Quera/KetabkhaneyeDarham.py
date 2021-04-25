import requests

def process(link):
    response = requests.get(link)
    if response.status_code != 200:
        return 'Bad Query'
    cats = set(map(lambda book: book['category'], response.json()))
    return list(cats)[0] if len(cats) == 1 else "I can't recognize it"