from math import sqrt


class Person:

    instances = []

    def __init__(self, name, age):
        self.name = name
        self.age = age
        self.level = 1
        self.job = ""
        self.work_place = None
        Person.instances.append(self)

    def do_level(self, income):
        return income * sqrt(self.level * self.work_place.level)

    def calc_income(self):
        pass

    def calc_life_cost(self):
        pass

    def calc(self):
        income, cost = self.calc_income(), self.calc_life_cost()
        return self.do_level(income) - cost

    @staticmethod
    def calc_all():
        return sum(map(lambda x: x.calc(), Person.instances))

    def get_job(self):
        return self.job

    def upgrade(self):
        self.level += 1