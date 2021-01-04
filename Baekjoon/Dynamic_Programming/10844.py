import sys

N = int(sys.stdin.readline())


def Solve():
    s = [[0 for _ in range(11)] for _ in range(N+1)]

    for i in range(1, 10):
        s[1][i] = 1
    for i in range(2, N+1):
        s[i][0] = s[i-1][1]

        for x in range(1, 10):
            s[i][x] = (s[i-1][x-1] + s[i-1][x+1]) % 1000000000

    
    result = 0


    for x in range(10):
        result += s[N][x]
    

    print(result % 1000000000)


Solve()
