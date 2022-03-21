#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int N, K = 0;
	int W[101] = { 0, };
	int Value[101] = { 0, };
	int DP[101][100001] = { {0,}, };

	cin >> N >> K;


	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> Value[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int c = 1; c <= K; c++)
		{
			if (c >= W[i]) {
				DP[i][c] = max(DP[i - 1][c], DP[i - 1][c - W[i]] + Value[i]);
			}
			else {
				DP[i][c] = DP[i-1][c];
			}
		}
	}

	cout << DP[N][K] << endl;



	return 0;
}
