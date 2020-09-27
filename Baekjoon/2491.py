import sys

N = int(sys.stdin.readline())

numList = []
numList = list(map(int, sys.stdin.readline().split()))

length = 1
_max = 1
for i in range(1, len(numList)):
    if(numList[i-1] <= numList[i]):
        length += 1
    else:
        length = 1
    if(length > _max):
        _max = length

length = 1
for i in range(1, len(numList)):
    if(numList[i-1] >= numList[i]):
        length += 1
    else:
        length = 1
    if(length > _max):
        _max = length

sys.stdout.write(str(_max))
