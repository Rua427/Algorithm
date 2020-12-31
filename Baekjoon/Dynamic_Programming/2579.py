import sys

s = int(sys.stdin.readline())

score = []
for _ in range(s):
    score.append(int(sys.stdin.readline()))


oneStep = [0] * (s+1)
twoStep = [0] * (s+1)

oneStep[1] = score[0]
twoStep[1] = score[0]

for i in range(2, s+1):
    oneStep[i] = twoStep[i-1] + score[i-1]
    numbers = max(oneStep[i-2], twoStep[i-2])
    twoStep[i] = numbers + score[i-1]

print(max(oneStep[-1], twoStep[-1]))
