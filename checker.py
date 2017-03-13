from os import popen
from random import randint, choice, uniform

def gen():
    n = randint(3, 5)
    # ...
    return test

for i in range(100):
    print i
    f = open('test.txt', 'w')
    test = gen()
    f.write(test)
    f.close()
    v1 = popen('./stupid < test.txt').read()
    v2 = popen('./run < test.txt').read()
    if v1 != v2:
        print "TEST"
        print test
        print "GOOD"
        print v1
        print "BAD"
        print v2
        break
