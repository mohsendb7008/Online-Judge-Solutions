class Proxy:

    def __init__(self, obj):
        self._obj = obj
        self.last = None
        self.counts = {}

    def __getattr__(self, attr):
        try:
            ga = getattr(self._obj, attr)
            self.last = attr
            self.counts[attr] = self.counts.get(attr, 0) + 1
            return ga
        except:
            raise Exception('No Such Method')
    
    def last_invoked_method(self):
        if self.last:
            return self.last
        raise Exception('No Method Is Invoked')

    def count_of_calls(self, method_name):
        return self.counts.get(method_name, 0)

    def was_called(self, method_name):
        return method_name in self.counts


class Radio:

    def __init__(self):
        self._channel = None
        self.is_on = False
        self.volume = 0

    def get_channel(self):
        return self._channel

    def set_channel(self, value):
        self._channel = value

    def power(self):
        self.is_on = not self.is_on


if __name__ == '__main__':
    radio = Radio()
    radio_proxy = Proxy(radio)
    radio_proxy.set_channel(95)
    print(radio_proxy.get_channel())