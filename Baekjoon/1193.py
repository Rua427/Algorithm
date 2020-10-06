import sys

X = int(sys.stdin.readline())

n=0
count = 1
while True:
    n += count
    if(n >= X):
        if(count % 2 == 1):
            x = 1
            y = count
            temp = n - X
            x += temp
            y -= temp
        else:
            x = 1
            y = count
            temp = n - X
            x += temp
            y -= temp
            temp = x
            x = y
            y = temp
        
        sys.stdout.write(str(x) + "/" + str(y))
        break
    count += 1
