import requests

def process(book):
    url = 'http://127.0.0.1:8000/' + book['category'] + '/'
    if book in requests.get(url).json():
        return 'bad query'
    requests.post(url, data = book)