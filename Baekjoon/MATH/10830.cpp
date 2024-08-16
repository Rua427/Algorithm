#include <iostream>
#include <vector>
#define P 1000
using namespace std;

typedef vector<vector<long long>> matrix;
matrix operator*(const matrix &a, const matrix &b)
{
    int size = a.size();
    matrix res(size, vector<long long>(size));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }

            res[i][j] %= P;
        }
    }

    return res;
}

void Print(const matrix &a)
{
    int size = a.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

matrix power(matrix a, long long n)
{
    int size = a.size();
    matrix res(size, vector<long long>(size, 0));
    // 행렬 항등원
    for (int i = 0; i < size; i++)
    {
        res[i][i] = 1;
    }

    while (n > 0)
    {
        if (n & 1)
        {
            res = res * a;
        }

        a = a * a;
        n >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long long B;
    cin >> N >> B;

    matrix square(N, vector<long long>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> square[i][j];
        }
    }

    Print(power(square, B));

    return 0;
}