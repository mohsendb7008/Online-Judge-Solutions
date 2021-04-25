def decorator(validator):
    def dec(f):
        def g(*x, **y):
            if validator(*x, **y):
                return f(*x, **y)
            else:
                return 'error'
        return g
    return dec