import sys

N = int(sys.stdin.readline())

table = [[0 for x in range(N)] for _ in range(N)]
dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

for i in range(N):
    num = sys.stdin.readline()
    for ii in range(N):
        table[i][ii] = int(num[ii])

queue = []

comflex = 0
_num = []
for y in range(N):
    for x in range(N):
        if(table[y][x] == 1):
            comflex += 1
            num = 0
            queue.append([y, x])
            while(len(queue) > 0):
                if(table[queue[0][0]][queue[0][1]] == 1):
                    table[queue[0][0]][queue[0][1]] = 0
                    num += 1
                for i in range(4):
                    nx = queue[0][1] + dx[i]
                    ny = queue[0][0] + dy[i]

                    if (0 <= nx < N and 0 <= ny < N and table[ny][nx] == 1):
                        queue.append([ny, nx])
                        table[ny][nx] = 0
                        num += 1

                del queue[0]
            _num.append(num)

print(comflex)
_num.sort()
for x in _num:
    print(x)
