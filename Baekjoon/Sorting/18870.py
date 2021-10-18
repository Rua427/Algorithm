import sys

N = int(sys.stdin.readline())
X = list(map(int, sys.stdin.readline().split()))
dic = dict();

sortedX = sorted(X)
dic[sortedX[0]] = 0


for i in range(1, len(sortedX)):
    if not sortedX[i] in dic:
        dic[sortedX[i]] = dic[sortedX[i - 1]] + 1


for x in X:
    sys.stdout.write(str(dic[x]) + " ")
