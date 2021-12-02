import sys

N, K = list(map(int, sys.stdin.readline().split()))

square = [0] * (N*N)
for i in range(N):
    num = list(map(int, sys.stdin.readline().split()))

    for index in range(N):
        square[index + (N * i)] = num[index]

for n in range(N, (N*N) + N, N):
    for _ in range(K):
        for i in square[n-N:n]:
            for _ in range(K):
                sys.stdout.write(str(i) + " ")
        sys.stdout.write("\n")
