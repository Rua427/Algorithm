import sys

N = int(sys.stdin.readline())

toDeliver = []
sugar = [5, 3]
select = 1

#DP
max = sugar[0] * sugar[1]
tempN = N
N = tempN % max
res = (tempN // max) * 3

if(res > 0):
    res -= 3
    N += 15

def solve(number):
    if(number < 0):
        return False
    if(number == 0):
        return True
    if(solve(number - 5)):
        toDeliver.append(sugar[-1])
        return True
    if(solve(number - 3)):
        toDeliver.append(sugar[0])
        return True

    return False
            
solve(N)

res += len(toDeliver)

if(res > 0):
    sys.stdout.write(str(res))
else:
    sys.stdout.write("-1")
