#include <iostream>
using namespace std;

int s[100000];
int e[100000];
int main() {
	
	int TC = 0;
	cin >> TC;

	for (int t = 1; t <= TC; t++)
	{
		int L = 0;
		int N = 0;

		cin >> L;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> s[i] >> e[i];
		}

		int endTime = 0;
		int overLapTime = 0;
		int overLapTimePrev = 0;
		int maxTime = 0;
		int prevIdx = 0;

		for (int i = 0; i < N; i++)
		{
			//overLapTime = 0;
			if (s[i] >= endTime) {
				overLapTime = 0;
				overLapTimePrev = 0;
				prevIdx = i - 1;
			}
			else if (i > 0) {
				overLapTime = overLapTimePrev -= (e[i - 1] - s[i - 1]);
			}
			endTime = s[i] + L;

			for (int c = prevIdx + 1; c < N; c++)
			{
				if (s[c] >= endTime) {
					break;
				}
				else if (e[c] > endTime) {
					overLapTime += endTime - s[c];
					break;
				}
				else {
					overLapTimePrev = overLapTime  += e[c] - s[c];
					prevIdx = c;
				}
			}
			maxTime = maxTime < overLapTime ? overLapTime : maxTime;
		}

		printf("#%d %d\n", t, maxTime);
	}
}
