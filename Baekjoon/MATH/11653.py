import sys
import math

N = int(sys.stdin.readline())

# 3개 이상의 소수로 구성된 합성수는 그 수의 제곱근보다 작거나 같은 약수를 갖는다고함
# https://movefast.tistory.com/175
m = math.sqrt(N)
for i in range(2, int(m) + 1):

    while (N % i == 0):
        sys.stdout.write(str(i) + "\n")
        N = int(N / i)

if(N != 1):
    sys.stdout.write(str(N) + "\n")

    
