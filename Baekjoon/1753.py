import sys
from heapq import heappush, heappop
V, E = map(int, sys.stdin.readline().split())
inf = 100000000
start = int(sys.stdin.readline())

node = [[] for _ in range(V)]

for _ in range(E):
    u, v, w = map(int, sys.stdin.readline().split())
    node[u-1].append([v-1, w])

distance = [inf] * V
distance[start - 1] = 0
select = start-1

heap = []
heappush(heap, [distance[select], select])

while heap:
    w, n = heappop(heap)
    for _n, _w in node[n]:
        newW = w + _w
        if(distance[_n] > newW):
            distance[_n] = newW
            heappush(heap, [newW, _n])

for i in distance:
    if(i == inf):
        print("INF")
    else:
        print(i)
