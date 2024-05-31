#include <iostream>
using namespace std;

int N = 0;
int *T, *P;
int maxPay = 0;
//dfs
void Calc(int day, int sumPay)
{
	if (day > N) return;

	maxPay = max(maxPay, sumPay);

	for (int i = day; i < N; i++)
	{
		Calc(T[i] + i, sumPay + P[i]);
	}
}

int main(){
    cin >> N;

	T = new int[N + 1];
	P = new int[N + 1];

	for (int i = 0; i < N; i++)
	{
		cin >> T[i] >> P[i];
	}

	Calc(0, 0);
	cout << maxPay;
}
