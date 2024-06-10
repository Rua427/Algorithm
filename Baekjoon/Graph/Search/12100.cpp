#include <iostream>
#include <stack>
#include <list>

using namespace std;

int N;
int maxResult = 0;

struct Map {
	int data[21][21] = { {0,} };
public:
	bool operator==(const Map& map) const {
		for (int y = 0; y < 21; y++)
		{
			for (int x = 0; x < 21; x++)
			{
				if (data[y][x] != map.data[y][x]) return false;
			}
		}

		return true;
	}
};
struct Board {
	Map map;
	int count;

	Board(Map m, int c) {
		count = c;
		map = m;
	}
};

int DFS(Board board);
void Move(Map& m, int i);
list<int> GetCalcList(list<int> _list);
void InsertCalcList(Map& m, list<int>& _list, int x, int y);


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


	int result = DFS(Board{ getMap, 0 });
	cout << result;

	return 0;
}

int DFS(Board board)
{

	stack<Board> s;
	s.push(board);
	while (!s.empty())
	{
		Board current = s.top();
		int count = s.top().count;
		s.pop();

		if (count >= 5) continue;

		for (int i = 0; i < 4; i++)
		{
			Map nm = current.map;
			int ncount = count + 1;
			Move(nm, i);

			if (current.map == nm) continue;

			Board next = Board(nm, ncount);
			s.push(next);
		}
	}

	return maxResult;
}

void Move(Map& m, int i)
{
	list<int> _list;
	list<int> value;
	//left
	if (i == 0) {
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				if (m.data[y][x] == 0) continue;
				value.push_back(m.data[y][x]);
			}

			_list = GetCalcList(value);

			for (int x = 1; x <= N; x++)
			{
				InsertCalcList(m, _list, x, y);
			}

			value.clear();
		}
	}
	//right
	else if (i == 1) {
		for (int y = 1; y <= N; y++)
		{
			for (int x = N; x > 0; x--)
			{
				if (m.data[y][x] == 0) continue;
				value.push_back(m.data[y][x]);
			}

			_list = GetCalcList(value);

			for (int x = N; x > 0; x--)
			{
				InsertCalcList(m, _list, x, y);
			}
			value.clear();
		}
	}
	// up
	else if (i == 2) {
		for (int x = 1; x <= N; x++)
		{
			for (int y = 1; y <= N; y++)
			{
				if (m.data[y][x] == 0) continue;
				value.push_back(m.data[y][x]);
			}

			_list = GetCalcList(value);
			for (int y = 1; y <= N; y++)
			{
				InsertCalcList(m, _list, x, y);
			}
			value.clear();
		}
	}
	//down
	else if (i == 3) {
		for (int x = 1; x <= N; x++)
		{
			for (int y = N; y > 0; y--)
			{
				if (m.data[y][x] == 0) continue;
				value.push_back(m.data[y][x]);
			}

			_list = GetCalcList(value);

			for (int y = N; y > 0; y--)
			{
				InsertCalcList(m, _list, x, y);
			}
			value.clear();
		}
	}
}

list<int> GetCalcList(list<int> v)
{
	list<int> _list;
	int value = 0;
	for (list<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		if (value == *it) {
			_list.pop_back();
			_list.push_back(*it * 2);
			value = 0;
			continue;
		}
		value = *it;
		_list.push_back(value);
	}

	return _list;
}

void InsertCalcList(Map& m, list<int>& _list, int x, int y)
{
	if (_list.empty()) m.data[y][x] = 0;
	else {
		m.data[y][x] = _list.front();
		if (m.data[y][x] > maxResult) maxResult = m.data[y][x];
		_list.pop_front();
	}
}
