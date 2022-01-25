#include <iostream>

using namespace std;

int MAX(int, int, int);

int main() {

	int grape[10001] = { 0, };
	int dp[10001] = { 0, };

	int count = 0;

	cin >> count;

	for (int i = 1; i <= count; i++)
	{
		cin >> grape[i];
	}

	dp[1] = grape[1];
	dp[2] = dp[1] + grape[2];

	for (int i = 3; i <= count; i++)
	{
		dp[i] = MAX(dp[i - 3] + grape[i - 1] + grape[i], dp[i - 2] + grape[i], dp[i - 1]);
	}

	cout << dp[count];

	return 0;
}

int MAX(int a, int b, int c) {

	int temp = a > b ? a : b;
	return temp = c > temp ? c : temp;
}
