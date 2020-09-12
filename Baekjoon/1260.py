import sys

N, M, V = map(int, sys.stdin.readline().split())

table = [[False for _ in range(N+1)] for _ in range(N+1)]


visited = [False for _ in range(N+1)]
visited[V] = True
visited2 = visited.copy()

search = []
search.append(V)
search2 = search.copy()

for _ in range(M):
    n1, n2 = map(int, sys.stdin.readline().split())
    table[n1][n2] = True
table2 = table.copy()

for s in range(N+1):
    if(s == 0):
        s = V
    for e in range(1, N+1):
        if(table[s][e] == True and not visited[e]):
            table[s][e] = False
            search.append(e)
            visited[e] = True
            s = e
            break

for s in range(N+1):
    if(s == 0):
        s = V
    for e in range(1, N+1):
        if(table[s][e] == True and not visited[e]):
            table[s][e] = False
            search.append(e)
            visited[e] = True
            s = e
            break

sys.stdout.write(str(search))
