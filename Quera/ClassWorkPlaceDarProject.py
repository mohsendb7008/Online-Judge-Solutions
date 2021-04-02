class WorkPlaceIsFull(Exception):

    def __str__(self):
        return "work place is full"


class Consts:

    BASE_PRICE = {'mine': 300, 'school': 100, 'company': 200}
    BASE_PLACE_COST = 1000
    LEVEL_MUL = 10


class WorkPlace:

    instances = []

    def __init__(self, name):
        WorkPlace.instances.append(self)
        self.name = name
        self.level = 1
        self.expertise = ""
        self.employees = []
        self.capacity = 1

    def calc_capacity(self):
        pass

    def calc_costs(self):
        pass

    def get_price(self):
        return Consts.BASE_PRICE[self.expertise]

    def upgrade(self):
        self.level += 1
        self.calc_capacity()

    def hire(self, person):
        if len(self.employees) == self.capacity:
            raise WorkPlaceIsFull
        self.employees.append(person)
        person.work_place = self

    def get_expertise(self):
        return self.expertise

    def calc(self):
        return -self.calc_costs()

    @staticmethod
    def calc_all():
        return sum(map(lambda x: x.calc(), WorkPlace.instances))
