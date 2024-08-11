#include <iostream>

using namespace std;

int N, K;

int Factorial(int start, int end)
{
    int result = 1;

    for (int i = start; i <= end; i++)
    {
        result = result * i;
    }

    return result;
}

int main()
{
    cin >> N >> K;

    int A = Factorial(1, N);
    int B = Factorial(1, N - K) * Factorial(1, K);
    int result = A / B;
    cout << result;

    return 0;
}