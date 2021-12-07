// 백준 연산자 끼워넣기 14888

#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int MAX = -1000000000;
int MIN = 1000000000;

// 주어진 수
int A[11] = { 0, };
// 주어진 연산자
int oper[4] = { 0, };

void Calc(int res, int idx, int _max) {
	if (idx > _max) {
		MAX = MAX < res ? res : MAX;
		MIN = MIN > res ? res : MIN;

		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		if (oper[i] != 0) {
			--oper[i];
			if (i == 0) {
				Calc(res + A[idx + 1], idx + 1, _max);
			}
			if (i == 1) {
				Calc(res - A[idx + 1], idx + 1, _max);
			}
			if (i == 2) {
				Calc(res * A[idx + 1], idx + 1, _max);
			}
			if (i == 3) {
				Calc(res / A[idx + 1], idx + 1, _max);
			}
			++oper[i];
		}
	}
}

int main(int argc, char* argv[])
{
	// 주어질 수의 개수
	int N = 0;
	cin >> N;


	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}


	Calc(A[0], 0, N - 2);

	cout << MAX << endl;
	cout << MIN;

}
