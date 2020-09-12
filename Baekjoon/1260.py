import sys

N, M, V = map(int, sys.stdin.readline().split())

table = [[False for _ in range(N+1)] for _ in range(N+1)]
table2 = [[False for _ in range(N+1)] for _ in range(N+1)]

visited = [False for _ in range(N+1)]
visited[V] = True
visited2 = visited.copy()

search = []
search.append(V)
search2 = search.copy()

for _ in range(M):
    n1, n2 = map(int, sys.stdin.readline().split())
    table[n1][n2] = True
    table[n2][n1] = True
    table2[n1][n2] = True
    table2[n2][n1] = True

stack = []
stack.append(V)

while(len(stack) > 0):
    for e in range(1, N+1):
        if(table[stack[-1]][e] == True and not visited[e]):
            stack.append(e)
            search.append(e)
            table[stack[-1]][e] = False
            visited[e] = True
            break
        if(e == N):
            del stack[-1]

queue = []
queue.append(V)

while(len(queue) > 0):
    for e in range(1, N+1):
        if(table2[queue[0]][e] == True and not visited2[e]):
            queue.append(e)
            search2.append(e)
            table2[queue[0]][e] = False
            visited2[e] = True
        if(e == N):
            del queue[0]

            
for i in search:
    sys.stdout.write(str(i) + " ")

sys.stdout.write("\n")
        
for i in search2:
    sys.stdout.write(str(i) + " ")

