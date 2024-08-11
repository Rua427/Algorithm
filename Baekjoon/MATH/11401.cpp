#include <iostream>

#define P 1000000007
using namespace std;

long long N, K;

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
long long Factorial(long long start, long long end)
{
    long long result = 1;

    for (long long i = start; i <= end; i++)
    {
        result = result * i % P;
    }

    return result;
}

int main()
{
    cin >> N >> K;

    long long A = Factorial(N - K + 1, N) % P;
    long long B = Factorial(1, K) % P;
    long long result = A * Power(B, P - 2) % P;
    cout << result;

    return 0;
}