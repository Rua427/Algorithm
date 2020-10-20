import sys

def Move(start, to):
    sys.stdout.write(str(start) + " " + str(to) + "\n")

def Hanoi(N, start, to, via):
    if(N == 1):
        Move(start, to)
        return
    else:
        Hanoi(N-1, start, via, to)
        Move(start, to)
        Hanoi(N-1, via, to, start)


N = int(sys.stdin.readline())

count = (2 ** N) - 1

sys.stdout.write(str(count) + "\n")
Hanoi(N, 1, 3, 2)
