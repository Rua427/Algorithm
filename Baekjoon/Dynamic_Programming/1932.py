import sys

n = int(sys.stdin.readline())

tri = []
for i in range(n):
    tri.append(list(map(int, sys.stdin.readline().split())))

result = []
result.append(tri[0])

for floor in range(1, n):
    prev = result[floor-1]
    numList = tri[floor]


    tempList = [0] * (floor+1)
    tempList[0] = numList[0] + prev[0]
    tempList[-1] = numList[-1] + prev[-1]

    for i in range(1, floor):
        tempList[i] = numList[i] + max(prev[i-1], prev[i])
    
    result.append(tempList)

print(max(result[-1]))
