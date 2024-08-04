/*
    중앙값 구하기
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main()
{
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    N--;

    int n;
    cin >> n;

    max_heap.push(n);
    cout << n << '\n';

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (max_heap.size() == min_heap.size())
            max_heap.push(num);
        else
            min_heap.push(num);

        int max = max_heap.top();
        int min = min_heap.top();

        if (max > min)
        {
            max_heap.pop();
            min_heap.pop();

            max_heap.push(min);
            min_heap.push(max);
        }

        cout << max_heap.top() << '\n';
    }

    return 0;
}