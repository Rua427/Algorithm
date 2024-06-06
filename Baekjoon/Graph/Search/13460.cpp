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
};

struct Bead
{
    Position p;

    Bead(Position _p)
    {
        p = _p;
    }
};

struct Board
{
    int count;
    list<Bead> beads;
};
char map[11][11];

// BFS
void Flip(list<Bead> beads)
{
}

int main()
{
    int N, M;

    cin >> N >> M;

    int rx, ry;
    int bx, by;
    for (int n = 1; n <= N; n++)
    {
        for (int m = 1; m <= M; m++)
        {
            cin >> map[n][m];

            if (map[n][m] == 'R')
            {
                rx = m;
                ry = n;
            }
            else if (map[n][m] == 'B')
            {
                bx = m;
                by = n;
            }
        }
    }

    Bead red = Bead(Position(rx, ry));
    Bead blue = Bead(Position(bx, by));

    Flip(list<Bead>({red, blue}));
    return 0;
}