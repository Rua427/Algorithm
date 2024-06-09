#include <iostream>
#include <stack>
#include <queue>
#include <list>
using namespace std;

int N;

struct Map {
	int data[21][21]= {{0,} };

};
struct Board {
	Map map;
	int count;

	Board(Map m, int c) {
		count = c;
		map = m;
	}
};

void Move(Map m, int i) {
	list<int> _list;
	list<int> value;
	//left
	if (i == 0) {
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				if (m.data[y][x] != 0) {

					if (!_list.empty() && _list.back() == m.data[y][x]) {
						value.push_back(_list.back() + m.data[y][x]);
						_list.pop_front();
						continue;
					}
					_list.push_back(m.data[y][x]);
				}
			}

			value.splice(value.end(), _list);

			for (int x = 1; x <= N; x++)
			{
				if (value.empty()) m.data[y][x] = 0;
				else {
					m.data[y][x] = value.front();
					value.pop_front();
				}
			}
		}
	}
	//right
	else if (i == 1) {
		for (int y = 1; y <= N; y++)
		{
			for (int x = N; x > 0; x--)
			{
				// 인접한 값
				if (m.data[y][x] != 0) {
					if (!_list.empty() && _list.back() == m.data[y][x]) {
						value.push_back(_list.back() + m.data[y][x]);
						_list.pop_front();
						continue;
					}
					_list.push_back(m.data[y][x]);
				}
			}

			for (int x = N; x > 0; x--)
			{
				if (value.empty()) m.data[y][x] = 0;
				else {
					m.data[y][x] = value.front();
					value.pop_front();
				}
			}
		}
	}
	// up
	else if (i == 2) {
		for (int x = 1; x <= N; x++)
		{
			for (int y = 1; y <= N; y++)
			{
				// 인접한 값
				if (m.data[y][x] != 0) {
					if (!_list.empty() && _list.back() == m.data[y][x]) {
						value.push_back(_list.back() + m.data[y][x]);
						_list.pop_front();
						continue;
					}

					_list.push_back(m.data[y][x]);
				}
			}

			for (int y = 1; y <= N; y++)
			{
				if (value.empty()) m.data[y][x] = 0;
				else {
					m.data[y][x] = value.front();
					value.pop_front();
				}
			}
		}
	}
	//down
	else if (i == 3) {
		for (int x = 1; x <= N; x++)
		{
			for (int y = N; y > 0; y--)
			{
				// 인접한 값
				if (m.data[y][x] != 0) {
					if (!_list.empty() && _list.back() == m.data[y][x]) {
						value.push_back(_list.back() + m.data[y][x]);
						_list.pop_front();
						continue;
					}

					_list.push_back(m.data[y][x]);
				}
			}

			for (int y = N; y > 0; y--)
			{
				if (value.empty()) m.data[y][x] = 0;
				else {
					m.data[y][x] = value.front();
					value.pop_front();
				}
			}
		}
	}
}

void DFS(Board board) {

	stack<Board> s;
	s.push(board);

	while (!s.empty()) {

		Board current = s.top();
		int count = s.top().count;
		s.pop();

		if (count >= 5) break;

		for (int i = 0; i < 4; i++)
		{
			Map m = current.map;
			int ncount = count + 1;
			Move(m, i);

			Board next = Board(m, ncount);
			s.push(next);
		}
	}
}

int main() {

	cin >> N;
	Map getMap;

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			cin >> getMap.data[y][x];
		}
	}

	DFS(Board{getMap, 0 });
	//int result = DFS(Board{map, 0});
	//cout << result;
	return 0;
}
