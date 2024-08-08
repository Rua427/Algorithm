#include <iostream>
#include <queue>

using namespace std;

#define MAX_R 1501
#define MAX_C 1501

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

struct node
{
    node *parent = nullptr;
};

struct pos
{
    int x, y;
};

char map[MAX_R][MAX_C];
bool visit[MAX_R][MAX_C];
node lake[MAX_R][MAX_C];
queue<pos> melt;
int R, C;
void SetMAP(queue<pos> w)
{
    while (!w.empty())
    {
        queue<pos> makeLake;
        makeLake.push(w.front());
        w.pop();
        node *_parent = &lake[makeLake.front().y][makeLake.front().x];

        while (!makeLake.empty())
        {
            pos p = makeLake.front();
            makeLake.pop();

            if (p.y > R || p.x > C || p.y < 1 || p.x < 1)
                continue;

            if (::visit[p.y][p.x] == true)
                continue;

            ::visit[p.y][p.x] = true;

            if (map[p.y][p.x] == 'X')
            {
                melt.push(p);
                continue;
            }

            lake[p.y][p.x].parent = _parent;

            for (int i = 0; i < 4; i++)
            {
                makeLake.push({p.x + dx[i], p.y + dy[i]});
            }
        }
    }
}

node *Find_root(node *n)
{
    if (n == n->parent)
        return n;

    return n->parent = Find_root(n->parent);
}

void Melting()
{
    queue<pos> nextMelt;
    while (!melt.empty())
    {
        queue<pos> makeLake;
        pos p = melt.front();

        melt.pop();

        map[p.y][p.x] = '.';
        // 빙판 녹은 지점 재 그룹화
        for (int i = 0; i < 4; i++)
        {
            int y = p.y + dy[i];
            int x = p.x + dx[i];

            if (y > R || x > C || y < 1 || x < 1)
                continue;

            if (map[y][x] == 'X')
                continue;

            if (lake[p.y][p.x].parent != nullptr)
            {
                Find_root(&lake[y][x])->parent = lake[p.y][p.x].parent;
                continue;
            }

            lake[p.y][p.x].parent = Find_root(&lake[y][x]);
        }

        // 다음날 녹을 지점 구함
        for (int i = 0; i < 4; i++)
        {
            int y = p.y + dy[i];
            int x = p.x + dx[i];
            if (map[y][x] != 'X')
                continue;

            if (::visit[y][x] == true)
                continue;

            ::visit[y][x] = true;
            nextMelt.push({x, y});
        }
    }

    melt = nextMelt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    queue<pos> water;
    queue<pos> swan;

    for (int y = 1; y <= R; y++)
    {
        for (int x = 1; x <= C; x++)
        {
            cin >> map[y][x];

            if (map[y][x] == 'X')
                continue;

            if (map[y][x] == 'L')
                swan.push({x, y});

            // 각 호수 구역
            if (map[y - 1][x] == '.' || map[y - 1][x] == 'L' || map[y][x - 1] == '.' || map[y][x - 1] == 'L')
                continue;

            water.push({x, y});
        }
    }

    SetMAP(water);
    int day = 0;

    while (true)
    {
        node *a = Find_root(&lake[swan.front().y][swan.front().x]);
        node *b = Find_root(&lake[swan.back().y][swan.back().x]);

        if (a == b)
        {
            cout << day << '\n';
            break;
        }

        Melting();
        ++day;
    }

    return 0;
}