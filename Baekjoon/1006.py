T = int(input())
for _ in range(T):
    N, W = map(int, input().split())

    enemyT = [[0 for col in range(N)] for row in range(2)]
    chkT = [[False for col in range(N)] for row in range(2)]
    linkT = [[0 for col in range(N)] for row in range(2)]

    enemyT[0][0:] = map(int, input().split())
    enemyT[1][0:] = map(int, input().split())

    count = 0
    for i in range(N*2):
        if(chkT[y][x] == True):
            continue

        y = i // N
        x = i % N
        s = [0 for _s in range(4)]
        
        tX = x-1
        s[0] = enemyT[y][x] + enemyT[y][tX]
        tX = x+1
        if(tx == N):
            tx = 0
        s[1] = enemyT[y][x] + enemyT[y][tX]
        s[2] = enemyT[y][x] + enemyT[y][tX-1]
        s[3] = enemyT[y][x] + enemyT[y][tX-1]

        done = False
        if(s == W):
            chkT[y][x] = True
            chkT[y][x-1] = True
            count += 1
            done = True
        elif(s < W):
            linkT[y][x] = s
            linkT[y][x-1] = s
            done = True
        
        if(not done):
            chkT[y][x] = True
            count += 1

