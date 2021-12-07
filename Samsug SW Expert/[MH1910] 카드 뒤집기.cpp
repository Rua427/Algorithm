#include <iostream>
using namespace std;


int main() {
	
	int TC = 0;
	cin >> TC;

	for (int t = 1; t <= TC; t++)
	{
		char _string[200001] = { 0, };
		cin >> _string;

		int bC = 0;
		unsigned long long flipCount = 0;
		
		for (int i = 0; _string[i] != '\0'; i++)
		{
			if (_string[i] == 'B') {
				++bC;
			}
			else if (_string[i] == 'W') {
				flipCount += bC;
			}
		}
		printf("#%d %llu\n", t, flipCount);
	}
}

