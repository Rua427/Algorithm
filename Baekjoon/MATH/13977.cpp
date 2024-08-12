#include <iostream>

#define P 1000000007
using namespace std;

long long N, K;

long long F[4000001];

long long Power(long long a, long long n)
{
    long long result = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            result = result * a % P;
        }
        a = a * a % P;
        n >>= 1;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // factorial cache
    F[0] = 1;
    for (int i = 1; i < 4000001; i++)
    {
        long long t = F[i - 1] * i % P;
        F[i] = t;
    }


    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> N >> K;
        long long A = F[N] % P;
        long long B = F[N - K] % P * F[K] % P;
        long long result = A * Power(B, P - 2) % P;
        cout << result << '\n';
    }

    return 0;
}