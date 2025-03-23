#include <iostream>
#include <list>
#include <queue>
using namespace std;

#define MAX 101

int map[MAX][MAX];
queue<pair<int, int>> snake;
queue<pair<int, char>> rotation;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int d = 0;
int n;

void Direction(char dir) {
	if (dir == 'L') {
		--d;
	}
	else {
		++d;
	}

	if (d < 0) {
		d = 3;
	}
	else if (d > 3) {
		d = 0;
	}
}

int Move() {

	int destX, destY;
	int time = 0;

	for (;;) {
		++time;

		destX = snake.back().first + dx[d];
		destY = snake.back().second + dy[d];
		// 뱀 길이를 늘림	
		snake.push({ destX, destY });

		if (destX <= 0 || destX > n || destY <= 0 || destY > n) {
			return time;
		}

		if (map[destY][destX] == 2)
			return time;

		if (map[destY][destX] != 1) {
			// 뱀 꼬리를 자름
			map[snake.front().second][snake.front().first] = 0;
			snake.pop();
		}

		map[destY][destX] = 2;

		if (rotation.empty()) continue;

		if (time >= rotation.front().first) {
			Direction(rotation.front().second);
			rotation.pop();
		}
	}
	return time;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int y, x;
	int sec;
	char dir;
	int l;
	int k;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			map[i][j] = 0;
		}
	}
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> y >> x;
		map[y][x] = 1;
	}
	cin >> l;

	for (int i = 0; i < l; i++)
	{
		cin >> sec >> dir;
		rotation.push({ sec, dir });
	}
	
	snake.push({ 1, 1 });
	map[1][1] = 2;
	int result = Move();
	cout << result;

	return 0;
}
