#include <cstring>
#include <iostream>
using namespace std;

int drop[1001];
int dp[3][31][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, w;
    cin >> t >> w;

    for (int i = 1; i <= t; i++)
    {
        cin >> drop[i];
    }

    memset(dp, -1, sizeof(dp));
    dp[1][w][0] = 0;

    for (int time = 0; time < t; time++)
    {
        for (int cnt = 0; cnt <= w; cnt++)
        {
            for (int pos = 1; pos <= 2; pos++)
            {
                if (dp[pos][cnt][time] < 0)
                    continue;

                int next = drop[time + 1];

                if (pos == next)
                {
                    dp[pos][cnt][time + 1] = dp[pos][cnt][time] + 1;
                }
                else
                {
                    if (cnt != 0)
                    {
                        dp[next][cnt - 1][time + 1] = max(dp[next][cnt - 1][time + 1], dp[pos][cnt][time] + 1);
                    }
                    dp[pos][cnt][time + 1] = dp[pos][cnt][time];
                }
            }
        }
    }

    int res = 0;
    for (int pos = 1; pos <= 2; pos++)
    {
        for (int time = 1; time <= t; time++)
        {
            res = max(res, dp[pos][0][time]);
        }
        for (int i = 0; i <= w; i++)
        {
            res = max(res, dp[pos][i][t]);
        }
    }

    cout << res;
}