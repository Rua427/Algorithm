import sys

N, M = map(int, sys.stdin.readline().split())


board = []

_min = 100

for _ in range(N):
  item = input()
  board.append(list(item))


for _y in range(N - 7):
  for _x in range(M - 7):
    wCount = 0
    bCount = 0
    for y in range(_y, _y + 8):
      for x in range(_x, _x + 8):
        if((x+y) % 2 == 0):
          if(board[y][x] == 'B'):
            wCount += 1
          else:
            bCount += 1
        else:
          if(board[y][x] == 'B'):
            bCount += 1
          else:
            wCount += 1
    if(_min > bCount):
      _min = bCount
    if(_min > wCount):
      _min = wCount

sys.stdout.write(str(_min))
