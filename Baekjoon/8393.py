#n이 주어졌을 때, 1부터 n까지 합을 구하는 프로그램을 작성하시오.


import sys

n = int(sys.stdin.readline())
result = 0
if (n % 2 == 0):
    n = n + 1
else:
    result += n
result += n * (n // 2)

sys.stdout.write(str(result))
