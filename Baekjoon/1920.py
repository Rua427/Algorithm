import sys

N = int(sys.stdin.readline())

A = [0 for _ in range(N)]
A[0:] = list(map(int, sys.stdin.readline().split()))
A.sort()

M = int(sys.stdin.readline())

B = [0 for _ in range(N)]
B[0:] = list(map(int, sys.stdin.readline().split()))

left = 0
right = N - 1

index = (left + right) // 2

result = []

for b in range(len(B)):
    while(left <= right):
        if(A[index] == B[b]):
            result.append("1")
            break
        elif(A[index] <= B[b]):
            left = index + 1
        elif(A[index] > B[b]):
            right = index - 1
        
        index = (left + right) // 2
    
    if(len(result) <= b):
        result.append("0")


for r in result:
    sys.stdout.write(r + "\n")
