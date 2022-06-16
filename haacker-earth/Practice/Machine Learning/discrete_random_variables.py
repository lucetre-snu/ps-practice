from sys import stdin
rf = stdin
# rf = open('input.txt', mode='r')

if __name__ == '__main__':
    p = float(rf.readline())
    print('%.6f' % (p/(1-p)**2))
