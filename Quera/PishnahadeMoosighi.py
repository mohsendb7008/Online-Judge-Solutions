albums, users = {}, {}


class Album:

    TYPE_ERROR_MESSAGE = "attribute '{}' of 'Album' objects requires {} (got type {})"
    ATTRIBUTE_ERROR_MESSAGE = "attribute '{}' of 'Album' objects is not writable"

    def __init__(self, name: str, singer: str, genre: str, tracks: int):
        if type(name) != str:
            raise TypeError(Album.TYPE_ERROR_MESSAGE.format('name', 'string', type(name)))
        if type(singer) != str:
            raise TypeError(Album.TYPE_ERROR_MESSAGE.format('singer', 'string', type(singer)))
        if type(genre) != str:
            raise TypeError(Album.TYPE_ERROR_MESSAGE.format('genre', 'string', type(genre)))
        if type(tracks) != int:
            raise TypeError(Album.TYPE_ERROR_MESSAGE.format('tracks', 'integer', type(tracks)))
        if not 1 <= tracks <= 100:
            raise ValueError(f"attribute 'tracks' of 'Album' objects must be in range 0..100 (got {tracks})")
        self.__name = name
        self.__singer = singer
        self.__genre = genre
        self.__tracks = tracks

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, value):
        raise AttributeError(Album.ATTRIBUTE_ERROR_MESSAGE.format('name'))

    @property
    def singer(self):
        return self.__singer

    @singer.setter
    def singer(self, value):
        raise AttributeError(Album.ATTRIBUTE_ERROR_MESSAGE.format('singer'))

    @property
    def genre(self):
        return self.__genre

    @genre.setter
    def genre(self, value):
        raise AttributeError(Album.ATTRIBUTE_ERROR_MESSAGE.format('genre'))

    @property
    def tracks(self):
        return self.__tracks

    @tracks.setter
    def tracks(self, value):
        raise AttributeError(Album.ATTRIBUTE_ERROR_MESSAGE.format('tracks'))

    class Builder:

        def __init__(self):
            self.kwargs = {}

        def name(self, name):
            self.kwargs['name'] = name
            return self

        def singer(self, singer):
            self.kwargs['singer'] = singer
            return self

        def genre(self, genre):
            self.kwargs['genre'] = genre
            return self

        def tracks(self, tracks):
            self.kwargs['tracks'] = tracks
            return self

        def build(self):
            return Album(**self.kwargs)

        @staticmethod
        def from_yaml(yaml):
            builder = Album.Builder()
            for line in yaml:
                key, value = line.split(': ')
                builder.kwargs[key[2:]] = int(value) if key[2:] == 'tracks' else value
            return builder.build()


class User:

    TYPE_ERROR_MESSAGE = "attribute '{}' of 'User' objects requires {} (got type {})"
    ATTRIBUTE_ERROR_MESSAGE = "attribute '{}' of 'User' objects is not writable"

    def __init__(self, name: str, age: int, city: str):
        if type(name) != str:
            raise TypeError(User.TYPE_ERROR_MESSAGE.format('name', 'string', type(name)))
        if type(age) != int:
            raise TypeError(User.TYPE_ERROR_MESSAGE.format('age', 'integer', type(age)))
        if not 0 <= age <= 200:
            raise ValueError(f"attribute 'age' of 'User' objects must be in range 0..200 (got {age})")
        if type(city) != str:
            raise TypeError(User.TYPE_ERROR_MESSAGE.format('city', 'string', type(city)))
        self.__name = name
        self.__age = age
        self.__city = city
        self.__albums = []

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, value):
        raise AttributeError(User.ATTRIBUTE_ERROR_MESSAGE.format('name'))

    @property
    def age(self):
        return self.__age

    @age.setter
    def age(self, value):
        raise AttributeError(User.ATTRIBUTE_ERROR_MESSAGE.format('age'))

    @property
    def city(self):
        return self.__city

    @city.setter
    def city(self, value):
        raise AttributeError(User.ATTRIBUTE_ERROR_MESSAGE.format('city'))

    @property
    def albums(self):
        return tuple(self.__albums)

    @albums.setter
    def albums(self, value):
        raise AttributeError(User.ATTRIBUTE_ERROR_MESSAGE.format('albums'))

    def purchase_album(self, album: Album):
        if type(album) != Album:
            raise TypeError("argument 'album' must be an object of class 'Album'")
        self.__albums.append(album)

    class Builder:

        def __init__(self):
            self.kwargs = {}

        def name(self, name):
            self.kwargs['name'] = name
            return self

        def age(self, age):
            self.kwargs['age'] = age
            return self

        def city(self, city):
            self.kwargs['city'] = city
            return self

        def build(self):
            return User(**self.kwargs)

        @staticmethod
        def from_yaml(yaml):
            builder, album_keys = User.Builder(), []
            for line in yaml:
                if line.startswith('    - '):
                    album_keys.append(line[6:])
                    continue
                if line == '  albums:':
                    continue
                key, value = line.split(': ')
                builder.kwargs[key[2:]] = int(value) if key[2:] == 'age' else value
            user = builder.build()
            for album_key in album_keys:
                user.purchase_album(albums[album_key])
            return user


class QueryExecutor:

    @staticmethod
    def query1(user: str, singer: str):
        if user not in users:
            return 0
        return sum(map(lambda album: album.tracks, filter(lambda album: album.singer == singer, users[user].albums)))

    @staticmethod
    def query2(user: str, genre: str):
        if user not in users:
            return 0
        return sum(map(lambda album: album.tracks, filter(lambda album: album.genre == genre, users[user].albums)))

    @staticmethod
    def query3(age: str, singer: str):
        ans = 0
        for user in filter(lambda user: user.age == int(age), users.values()):
            ans += sum(map(lambda album: album.tracks, filter(lambda album: album.singer == singer, user.albums)))
        return ans

    @staticmethod
    def query4(age: str, genre: str):
        ans = 0
        for user in filter(lambda user: user.age == int(age), users.values()):
            ans += sum(map(lambda album: album.tracks, filter(lambda album: album.genre == genre, user.albums)))
        return ans

    @staticmethod
    def query5(city: str, singer: str):
        ans = 0
        for user in filter(lambda user: user.city == city, users.values()):
            ans += sum(map(lambda album: album.tracks, filter(lambda album: album.singer == singer, user.albums)))
        return ans

    @staticmethod
    def query6(city: str, genre: str):
        ans = 0
        for user in filter(lambda user: user.city == city, users.values()):
            ans += sum(map(lambda album: album.tracks, filter(lambda album: album.genre == genre, user.albums)))
        return ans


query_reference = {
        '1': QueryExecutor.query1,
        '2': QueryExecutor.query2,
        '3': QueryExecutor.query3,
        '4': QueryExecutor.query4,
        '5': QueryExecutor.query5,
        '6': QueryExecutor.query6
    }

if __name__ == '__main__':
    users_yaml, albums_yaml = [], []
    n = int(input())
    line = input()
    for i in range(n):
        user_yaml = [line]
        while not (line := input()).startswith('- name:') and not line.isdigit():
            user_yaml.append(line)
        users_yaml.append(user_yaml)
    m = int(line)
    line = input()
    for i in range(m):
        album_yaml = [line]
        while not (line := input()).startswith('- name:') and not line.isdigit():
            album_yaml.append(line)
        albums_yaml.append(album_yaml)
    for album_yaml in albums_yaml:
        album = Album.Builder.from_yaml(album_yaml)
        albums[album.name] = album
    for user_yaml in users_yaml:
        user = User.Builder.from_yaml(user_yaml)
        users[user.name] = user
    q = int(line)
    for i in range(q):
        key, param1, param2 = input().split()
        print(query_reference[key](param1, param2))