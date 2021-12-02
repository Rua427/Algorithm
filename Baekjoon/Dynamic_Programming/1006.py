"""
초라기는 한국의 비밀국방기지(원타곤)를 습격하라는 임무를 받은 특급요원이다. 원타곤의 건물은 도넛 형태이며,
초라기는 효율적인 타격 포인트를 정하기 위해 구역을 아래와 같이 두 개의 원 모양으로 나누었다. (그림의 숫자는 각 구역의 번호이다.)



초라기는 각각 W명으로 구성된 특수소대를 다수 출동시켜 모든 구역에 침투시킬 예정이며,
각 구역 별로 적이 몇 명씩 배치되어 있는지는 초라기가 모두 알고 있다. 특수소대를 아래 조건에 따라 침투 시킬 수 있다.

한 특수소대는 침투한 구역 외에, 인접한 한 구역 더 침투할 수 있다. (같은 경계를 공유하고 있으면 인접 하다고 한다.
위 그림에서 1구역은 2, 8, 9 구역과 서로 인접한 상태다.) 즉, 한 특수소대는 한 개 혹은 두 개의 구역을 커버할 수 있다.

특수소대끼리는 아군인지 적인지 구분을 못 하기 때문에, 각 구역은 하나의 소대로만 커버해야 한다.
한 특수소대가 커버하는 구역의 적들의 합은 특수소대원 수 W 보다 작거나 같아야 한다.
이때 초라기는 원타곤의 모든 구역을 커버하기 위해 침투 시켜야 할 특수 소대의 최소 개수를 알고 싶어 한다.

"""

def Solve(start):
    for i in range(start, N):
        a[i+1] = min(b[i]+1, c[i]+1)
        if(e[0][i] + e[1][i] <= W):
            a[i+1] = min(a[i+1], a[i]+1)
        if(i > 0 and e[0][i-1] + e[0][i] <= W and e[1][i-1] + e[1][i] <= W):
            a[i+1] = min(a[i+1], a[i-1]+2)
        if(i < N-1):
            b[i+1] = a[i+1]+1
            if(e[0][i] + e[0][i+1] <= W):
                b[i+1] = min(b[i+1], c[i]+1)
            c[i+1] = a[i+1]+1
            if(e[1][i] + e[1][i+1] <= W):
                c[i+1] = min(c[i+1], b[i]+1)

T = int(input())
for _ in range(T):
    N, W = map(int, input().split())
    result = 30000
    a = [0 for _ in range(N+1)]
    b = [0 for _ in range(N)]
    c = [0 for _ in range(N)]

    e = [[0 for _ in range(N+1)]for _ in range(2)]
    e[0][0:] = map(int, input().split())
    e[1][0:] = map(int, input().split()) 

    a[0] = 0
    b[0] = 1
    c[0] = 1
    Solve(0)

    result = min(30000, a[N])

    if(N > 1):
        if(e[0][0] + e[0][-1] <= W):
            a[1] = 1
            b[1] = 2
            c[1] = 1 if e[1][0] + e[1][1] <= W else 2
            Solve(1)
            result = min(result, c[N-1]+1)
        if(e[1][0] + e[1][-1] <= W):
            a[1] = 1
            b[1] = 1 if e[0][0] + e[0][1] <= W else 2
            c[1] = 2
            Solve(1)
            result = min(result, b[N-1]+1)
        if(e[0][0] + e[0][-1] <= W and e[1][0] + e[1][-1] <= W):
            a[1] = 0
            b[1] = 1
            c[1] = 1
            Solve(1)
            result = min(result, a[N-1]+2)

    print(result)
