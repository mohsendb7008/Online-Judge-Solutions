from models import Product, User


class Store:

    def __init__(self):
        self.products = dict()
        self.users = list()

    def add_product(self, product, amount=1):
        self.products[product] = self.products.get(product, 0) + amount

    def remove_product(self, product, amount=1):
        if product not in self.products:
            raise Exception('Not Enough Products')
        curr = self.products[product]
        if amount > curr:
            raise Exception('Not Enough Products')
        elif amount == curr:
            del self.products[product]
        else:
            self.products[product] -= amount

    def add_user(self, username):
        user = User(username)
        if user in self.users:
            return None
        self.users.append(user)
        return username

    def get_total_asset(self):
        return sum(map(lambda p: p[0].price * p[1], self.products.items()))

    def get_total_profit(self):
        return sum(map(lambda user: sum(map(lambda p: p.price, user.bought_products)), self.users))
        
    def get_comments_by_user(self, user):
        ans = []
        for product in self.products.keys():
            ans += list(map(lambda c: c.text, filter(lambda c: c.user == user, product.comments)))
        return ans

    def get_inflation_affected_product_names(self):
        ans = set()
        for p1 in self.products.keys():
            ia = False
            for p2 in self.products.keys():
                if p1 != p2 and p1.name == p2.name and p1.price > p2.price:
                    ia = True
                    break
            if ia:
                ans.add(p1.name)
        return list(ans)

    def clean_old_comments(self, date):
        for product in self.products.keys():
            rm = []
            for i, c in enumerate(product.comments):
                if c.date_added < date:
                    rm.append(i)
            for i in reversed(rm):
                product.comments.pop(i)

    def get_comments_by_bought_users(self, product):
        return list(map(lambda c: c.text, filter(lambda c: product in c.user.bought_products, product.comments)))
