#include <iostream>
#include <string>
#include <map>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, bool, greater<string>> log;
	int N;
	cin >> N;
	string name;
	string state;

	for (int n = 0; n < N; n++)
	{
		cin >> name >> state;
		log[name] = state == "enter" ? true : false;
	}

	for (auto& l : log)
	{
		if (l.second == false) continue;

		cout << l.first << '\n';
	}

	return 0;
}
