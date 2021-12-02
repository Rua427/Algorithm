import sys

N = int(sys.stdin.readline())

num = [1] * 1001

l = list(map(int, sys.stdin.readline().split()))
for x in l:
    num[x] = x

num[1] = 0


for y in range(2, 1001):
    if(num[y] == 0):
        continue
    
    for x in range(y+y, 1001, y):
        num[x] = 0

count = 0

for i in num:
    if(i > 1):
        count += 1


print(count)
