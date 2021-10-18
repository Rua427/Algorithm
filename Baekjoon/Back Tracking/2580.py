import sys


sdoku = []
empty = []
for _ in range(9):
    sdoku.append(list(map(int, sys.stdin.readline().split())))
    for i in range(len(sdoku[-1])):
        if(sdoku[-1][i] == 0):
            empty.append(list([len(sdoku) - 1, i]))


def Get(y, x):
    searchList = set(range(1, 10))
    searchList -= set(sdoku[y])
    temp = set()
    for i in range(9):
        temp.add(sdoku[i][x])
    searchList -= temp
    temp = set()
    for i in range(y // 3 * 3, y // 3 * 3 + 3):
        for j in range(x // 3 * 3, x // 3 * 3 + 3):
            temp.add(sdoku[i][j])
    searchList -= temp
    return tuple(searchList)

def Solve(i):
    if( i == len(empty)):
        Print()
        sys.exit()

    y, x = empty[i]
    possible = Get(y, x)
    # 정답이 아닐수도 있기때문에 재 탐색해야함
    for n in possible:
        sdoku[y][x] = n
        Solve(i + 1)
        sdoku[y][x] = 0

def Print():
    for r in sdoku:
        for c in r:
            sys.stdout.write(str(c) + " ")
        sys.stdout.write("\n")

Solve(0)
