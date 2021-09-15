from datetime import datetime, timedelta

coins = {
    100: 10,
    50: 10,
    10: 10,
    5: 10,
    1: 10
}

def pay_cash(req):
    pull = {}
    for coin, cnt in coins.items():
        d = min(req // coin, cnt)
        req -= d * coin
        pull[coin] = d
    if req != 0:
        raise ValueError('Not Enough Banknotes!')
    for coin, d in pull.items():
        coins[coin] -= d


class User:

    instances = {}

    @staticmethod
    def from_username(username):
        if username not in User.instances:
            raise ValueError('No Such User Found!')
        return User.instances[username]

    def __init__(self, username):
        if username in User.instances:
            raise ValueError('Duplicate User!')
        self.username = username
        self.money = 100
        User.instances[username] = self

class Command:

    def __init__(self, index, line):
        self.index = index
        self.tokens = line.split(' ')
        self.timestamp = self.tokens.pop()
        self.timestamp = datetime.strptime(self.timestamp, '%Y/%m/%d-%H:%M:%S')

payments = []

def process(cmd):
    while payments and payments[0][0] <= cmd.timestamp:
        _, receiver, amount = payments.pop(0)
        receiver.money += amount
    token = cmd.tokens
    if token[0] == 'REGISTER':
        User(token[1])
        return 'Registered Successfully'
    elif token[0] == 'DEPOSIT':
        user = User.from_username(token[1])
        amount = int(token[2])
        user.money += amount
        return user.money
    elif token[0] == 'WITHDRAW':
        user = User.from_username(token[1])
        amount = int(token[2])
        if amount > 200:
            raise ValueError('Maximum Amount Exceeded!')
        if user.money < amount:
            raise ValueError('Not Enough Fund!')
        pay_cash(amount)
        user.money -= amount
        return user.money
    elif token[0] == 'TRANSFER':
        sender = User.from_username(token[1])
        receiver = User.from_username(token[2])
        amount = int(token[3])
        if amount > 3000:
            raise ValueError('Maximum Amount Exceeded!')
        if sender.money < amount:
            raise ValueError('Not Enough Fund!')
        sender.money -= amount
        payments.append((cmd.timestamp + timedelta(hours=1), receiver, amount))
        return sender.money
    elif token[0] == 'GET_BALANCE':
        user = User.from_username(token[1])
        if user.money < 10:
            raise ValueError('Not Enough Fund!')
        user.money -= 10
        return user.money
    elif token[0] == 'ADD_BANKNOTE':
        value = int(token[1])
        amount = int(token[2])
        coins[value] += amount
        return sum(list(map(lambda x: x[0] * x[1], coins.items())))

if __name__ == '__main__':
    n = int(input())
    commands = []
    for i in range(n):
        commands.append(Command(i, input()))
    commands.sort(key = lambda x: x.timestamp)
    for command in commands:
        try:
            command.result = process(command)
        except ValueError as e:
            command.result = str(e)
    commands.sort(key = lambda x: x.index)
    for command in commands:
        print(command.result)

