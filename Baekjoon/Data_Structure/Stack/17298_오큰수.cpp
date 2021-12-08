// 백준 오큰수 17298

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int N = 1000000;
int number[1000001] = { 0, };
int nge[1000001];
int MAX = 0;


int main(int argc, char* argv[])
{
	// 주어질 수의 개수

	cin >> N;
	int idx = 0;
	stack<int> _stack;
	for (int i = 1; i <= N; i++)
	{
		cin >> number[i];
		nge[i] = -1;
	}


	for (int i = 1; i <= N; i++)
	{
		while (!_stack.empty()) {
			if (number[_stack.top()] < number[i]) {
				nge[_stack.top()] = number[i];
				_stack.pop();
			}
			else {
				_stack.push(i);
				break;
			}
		}
		if (_stack.empty()) {
			_stack.push(i);
		}
	}

	

	for (int i = 1; i <= N; i++)
	{
		cout << nge[i];

		if (i == N) {
			cout << endl;
		}
		else {
			cout << " ";
		}
	}
}
