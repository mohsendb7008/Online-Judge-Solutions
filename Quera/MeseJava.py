from threading import Thread, Lock

lock = Lock()

def synchronized(f):
    def g(*args, **kwargs):
        global lock
        lock.acquire()
        ret = f(*args, **kwargs)
        lock.release()
        return ret
    return g

a = 0

@synchronized
def f():
    global a
    for i in range(300000):
        a = a + 1

if __name__ == '__main__':
    t = Thread(target=f)
    t.start()
    s = Thread(target=f)
    s.start()
    t.join()
    s.join()
    print(a)