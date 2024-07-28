#include <iostream>

using namespace std;
int main()
{

    int TC = 0;

    cin >> TC;
    for (int i = 0; i < TC; i++)
    {
        int N = 0;
        cin >> N;

        int p[5];

        for (int n = 0; n < N; n++)
        {
            cin >> p[n];
        }

        int resultMin = 5;
        int resultMax = 1;
        // 기준 위치에 있는 속도 값보다 낮은 값의 개수를 오른쪽에서 구하고 가장 작은 수를 구함
        // 그리고 기준 위치 왼쪽에서 구한 가장 작은 수보다 큰 값의 개수를 구함
        // 기준 위치에 있는 속도 값보다 큰 값의 개수를 오른쪽에서 구하고 가장 큰 수를 구함
        // 그리고 기준 위치 오른쪽에서 구한 가장 큰 수보다 작은 값의 개수를 구함

        for (int n = 0; n < N; n++)
        {
            int min = 9999;
            int max = -1;

            // 최소 값 구함
            for (int x = n + 1; x < N; x++)
            {
                if (p[x] < p[n] && min > p[x])
                    min = p[x];
            }
            // 최대 값 구함
            for (int x = n - 1; x >= 0; x--)
            {
                if (p[x] > p[n] && max < p[x])
                    max = p[x];
            }

            int result = 1;

            for (int x = n + 1; x < N; x++)
            {
                if (p[x] < max || p[n] > p[x])
                    result++;
            }
            for (int x = n - 1; x >= 0; x--)
            {
                if (p[x] > min || p[n] < p[x])
                    result++;
            }

            resultMax = resultMax < result ? result : resultMax;
            resultMin = resultMin > result ? result : resultMin;
        }

        cout << resultMin << " " << resultMax << endl;
    }

    return 0;
}