from sys import stdin
rf = stdin
# rf = open('in.txt', mode='r')

if __name__ == '__main__':
    T = int(rf.readline())
    for _ in range(T):
        N, L = [int(j) for j in rf.readline().split()]
        a = []
        for i in range(N):
            a.append([int(j) for j in rf.readline().split()])
        a.sort()
        flag = False
        for i in range(N):
            maxR = a[i][0] + L
            curL = a[i][0]
            curR = a[i][1]
            for j in range(N):
                if curL < a[j][0] <= curR and a[j][1] <= maxR:
                    curR = max(curR, a[j][1])
            if curR == maxR:
                flag = True
                break
        print('Yes' if flag else 'No')
