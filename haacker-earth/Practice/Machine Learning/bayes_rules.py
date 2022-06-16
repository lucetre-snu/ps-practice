from sys import stdin
rf = stdin
# rf = open('input.txt', mode='r')

if __name__ == '__main__':
    p_ct = float(rf.readline())
    p_ot = float(rf.readline())
    N = int(rf.readline())
    p = p_ot * (1-p_ct) + (2/N) * p_ct
    print('%.6f' % p)
