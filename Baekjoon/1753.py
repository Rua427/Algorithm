import sys

V, E = map(int, sys.stdin.readline().split())

start = int(sys.stdin.readline())

node = [[] for _ in range(V)]

for _ in range(E):
    u, v, w = map(int, sys.stdin.readline().split())
    node[u-1].append([v-1, w])

distance = [11 for _ in range(V)]
distance[start - 1] = 0
select = start-1




while True:
    short = []
    for i in node[select]:
        distance[i[0]] = min(distance[select] + i[1], distance[i[0]])
        short.append([i[0], distance[i[0]]])

    if(len(short) == 0):
        break

    short = sorted(short, key = lambda x : x[1])
    select = short[0][0]


for i in distance:
    if(i == 11):
        sys.stdout.write(str("INF\n"))
    else:
        sys.stdout.write(str(i)+"\n")
