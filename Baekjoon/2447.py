import sys

N = int(sys.stdin.readline())

table = [[' ' for _ in range(N)] for _ in range(N)]

def Paint(n, x, y):
    if(n == 1):
        table[y][x] = "*"
        return
    
    div = n // 3
    for _y in range(3):
        for _x in range(3):
            if(_y == _x == 1):
                continue
            
            Paint(div, x + (div*_x), y + (div*_y))

    return

Paint(N, 0, 0)

for y in range(N):
    for x in range(N):
        sys.stdout.write(str(table[y][x]))
    
    sys.stdout.write("\n")
