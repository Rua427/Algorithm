#include <iostream>
#include <queue>
#include <list>
using namespace std;

struct Position
{
    int x;
    int y;
    Position()
    {
        x = 0;
        y = 0;
    }
    Position(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    bool operator==(const Position &other) const
    {
        return (x == other.x && y == other.y);
    }
};

struct Bead
{
    Position p;
    Position back;

    Bead(Position _p, Position _back)
    {
        p = _p;
        back = _back;
    }
};

struct Board
{
    Bead beads[2];
    int count;
};

char map[11][11];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void Move(Position &pos, int &dist, int idx)
{
    while (map[pos.y + dy[idx]][pos.x + dx[idx]] != '#' &&
           map[pos.y][pos.x] != 'O')
    {
        pos.y += dy[idx];
        pos.x += dx[idx];
        dist++;
    }
}
// BFS
int BFS(Bead beads[2])
{
    queue<Board> q;
    q.push({beads[0], beads[1], 0});

    while (!q.empty())
    {
        Board current = q.front();
        int count = q.front().count;
        q.pop();

        if (count >= 10)
            break;

        for (int i = 0; i < 4; i++)
        {
            Bead red = current.beads[0];
            Bead blue = current.beads[1];
            int ncount = count + 1;
            int rdist = 0, bdist = 0;

            Move(red.p, rdist, i);
            Move(blue.p, bdist, i);

            if (map[blue.p.y][blue.p.x] == 'O')
                continue;
            if (map[red.p.y][red.p.x] == 'O')
                return ncount;

            // 겹쳤을때
            if (red.p == blue.p)
            {
                if (rdist < bdist)
                    blue.p.x -= dx[i], blue.p.y -= dy[i];
                else
                    red.p.x -= dx[i], red.p.y -= dy[i];
            }
            // 이동한 곳이 이전이랑 같을때
            if (red.p == red.back && blue.p == blue.back)
                continue;

            // 이동하기 전 좌표를 저장
            red.back = current.beads[0].p;
            blue.back = current.beads[1].p;

            q.push({red, blue, ncount});
        }
    }

    return -1;
}

int main(int argc, char **argv)
{
    int N, M;

    cin >> N >> M;

    Position r;
    Position b;
    for (int n = 1; n <= N; n++)
    {
        for (int m = 1; m <= M; m++)
        {
            cin >> map[n][m];

            if (map[n][m] == 'R')
            {
                r.x = m;
                r.y = n;
            }
            else if (map[n][m] == 'B')
            {
                b.x = m;
                b.y = n;
            }
        }
    }

    Bead beads[2] = {{r, Position()}, {b, Position()}};
    int res = BFS(beads);
    cout << res;
    return 0;
}
