from sys import stdin
import math

rf = stdin
# rf = open('input.txt', mode='r')


def exp_distributed_prob(x, lamb=0.01):
    return math.exp(-lamb * x)


if __name__ == '__main__':
    N = int(rf.readline())
    print('%.6f' % exp_distributed_prob(N))
