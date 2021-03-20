class ExceptionProxy(Exception):

    def __init__(self, msg, function):
        self.msg = msg
        self.function = function


def transform_exceptions(func_ls):
    ans = []
    for func in func_ls:
        try:
            func()
            ans.append(ExceptionProxy('ok!', func))
        except Exception as e:
            ans.append(ExceptionProxy(str(e), func))
    return ans