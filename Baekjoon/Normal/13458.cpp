#include <iostream>
using namespace std;

int main(){
  int N = 0;
	int B, C = 0;

	cin >> N;

	int* A = new int[N];

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		A[i] = num;
	}

	cin >> B >> C;

	long long result = N;

	for (int i = 0; i < N; i++)
	{
		int first = A[i] - B;

		int n1 = first / C;
		int n2 = first % C;

		if (n1 > 0) result += n1;
		if (n2 > 0) result++;
	}

	cout << result;
	delete[] A;
}
