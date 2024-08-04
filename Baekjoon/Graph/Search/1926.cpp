#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 501
#define MAX_M 501

struct Position
{
    int x, y;
};

int main()
{
    int n, m;
    bool map[MAX_N][MAX_M] = {
        false,
    };
    bool visit[MAX_N][MAX_M] = {
        false,
    };
    queue<Position> pos;
    cin >> n >> m;

    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= m; x++)
        {
            int input = 0;
            cin >> input;

            map[y][x] = input == 1 ? true : false;

            if (map[y - 1][x] || map[y][x - 1])
                continue;

            if (!map[y][x])
                continue;

            pos.push({x, y});
        }
    }

    int count = 0;
    int maxSize = 0;
    while (!pos.empty())
    {
        Position temp = pos.front();
        pos.pop();

        if (visit[temp.y][temp.x])
            continue;

        queue<Position> thisPos;
        thisPos.push(temp);

        int size = 0;

        while (!thisPos.empty())
        {
            Position p = thisPos.front();
            thisPos.pop();

            if (visit[p.y][p.x])
                continue;

            size++;

            if (map[p.y][p.x - 1])
                thisPos.push({p.x - 1, p.y});

            if (map[p.y + 1][p.x])
                thisPos.push({p.x, p.y + 1});

            if (map[p.y][p.x + 1])
                thisPos.push({p.x + 1, p.y});

            if (map[p.y - 1][p.x])
                thisPos.push({p.x, p.y - 1});

            visit[p.y][p.x] = true;
        }

        count++;
        maxSize = max(maxSize, size);
    }

    cout << count << endl;
    cout << maxSize << endl;
}