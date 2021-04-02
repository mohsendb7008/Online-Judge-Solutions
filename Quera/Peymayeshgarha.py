class Reverse:

    def __init__(self, data):
        self.data = data

    def __iter__(self):
        return Reverse.ReverseIterator(self)

    class ReverseIterator:

        def __init__(self, rev):
            self.rev = rev
            self.index = len(rev.data) - 1

        def __next__(self):
            if self.index == -1:
                raise StopIteration
            self.index -= 1
            return self.rev.data[self.index + 1]