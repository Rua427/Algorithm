#include <iostream>
#include <unordered_map>
#include <cmath>
// a^k 의 값이 N에 가장 근접하는 값중 k의 최대 값
// 2^60
#define MAX 61
#define MAX_R 999999999
#define ll long long

using namespace std;

unordered_map<ll, ll> dp;
int limit[MAX];
const double limit_exp = log(1LL << 60);

int SetLimitExp(int K) {
	int left = 2, right = 1e9, mid;

	while (left <= right) {
		mid = (left + right) >> 1;
		// a^k에서 가질수 있는 최대값 2^60 이하이어야함
		if (K * log(mid) <= limit_exp)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return right;
}

// 오버플로 발생하는데..
ll Power(ll a, int b) {
	ll result = 1;
	if (a == 1) return 1;

	while (b > 0) {
		if (b & 1) 
			result *= a;
		a *= a;
		b >>= 1;
	}
	return result;
}
// N에 근접하는 a^k <= N 값중 a의 최대 값 탐색
int SearchMAX_A(ll n, int K, int limit) {
	// limit을 정해 오버플로 방지
	int right = limit;
	int left = 1;

	while (left <= right) {
		int mid = (left + right) >> 1;
		ll power = Power((ll)mid, K);

		if (power == n) return left;

		if (power < n)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return right;
}



ll Searching(ll n) {
	if (n == 1) return 0;
	if (dp[n]) return dp[n];

	dp[n] = n - 1;
	for (int i = MAX - 1; i > 1; --i)
	{
		int left = SearchMAX_A(n, i, limit[i]);
		int right = left + 1;

		ll _left = abs(n - Power(left, i));
		ll _right = abs(n - Power(right, i));

		if (1 < left && 2e9 > _left)
			dp[n] = min(dp[n], Searching(left) + 1 + _left);
		if (1 < right && 2e9 > _right)
			dp[n] = min(dp[n], Searching(right) + 1 + _right);
	}
	return dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N;
	cin >> N;

	for (int i = 2; i < MAX; i++)
	{
		limit[i] = SetLimitExp(i);
	}
	cout << Searching(N);

	return 0;
}
