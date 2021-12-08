// 백준 스타트와 링크 14889

#include <iostream>
#include <stack>

using namespace std;

int MIN = 1000000000;

int table[20][20] = { {0,}, };
bool visitTable[20] = { {false}, };

int N = 0;

void DFS(int, int);
void DivideTeam();
int GetScore(int*);

void DFS(int s, int len) {
	if (len >= N / 2) {
		DivideTeam();
		return;
	}
	else {
		for (int i = s; i < N; i++)
		{
			visitTable[i] = true;
			DFS(i + 1, len + 1);
			visitTable[i] = false;
		}
	}
}

void DivideTeam() {
	int* start	= new int[N / 2];
	int* link	= new int[N / 2];

	int idxStart = 0;
	int idxLink = 0;
	for (int i = 0; i < N; i++)
	{
		if (visitTable[i] == true) { start[idxStart++] = i; }
		if (visitTable[i] == false) { link[idxLink++] = i; }
	}

	int startScore = GetScore(start);
	int linkScore = GetScore(link);

	int res = abs(startScore - linkScore);

	MIN = MIN > res ? res : MIN;
}

int GetScore(int* team) {

	int score = 0;
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = 0; j < N / 2; j++)
		{
			if (i == j) break;
			score += (table[team[j]][team[i]] + table[team[i]][team[j]]);
		}
	}

	return score;
}


int main(int argc, char* argv[])
{
	// 주어질 수의 개수

	cin >> N;


	stack<int> team[2];

	int teamScore[2]		= { 0, };

	// 테이블 입력
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> table[y][x];
		}
	}
	DFS(0, 0);

	cout << MIN;

}
