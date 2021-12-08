// 백준 바이러스 2606

#include <iostream>
#include <stack>

using namespace std;

int N = 0;
int Net = 0;

bool computers[101][101] = { {false,}, };
bool visit[101] = { false, };
int result = 0;

void DFS(int idx) {
	for (int i = 1; i <= N; i++)
	{
		if (idx == i) {
			continue;
		}
		if (computers[idx][i] == true && visit[i] == false) {
			result += 1;
			visit[i] = true;
			DFS(i);
		}
	
	}
}

int main(int argc, char* argv[])
{
	// 주어질 수의 개수

	cin >> N;
	cin >> Net;

	for (int i = 0; i < Net; i++)
	{
		int x, y = 0;

		cin >> x >> y;

		computers[x][y] = true;
		computers[y][x] = true;
	}

	visit[1] = true;
	DFS(1);

	cout << result;
}
