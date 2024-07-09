#include <iostream>
#include <list>
using namespace std;

int main(int argc, char** argv) {
    int test_case;
    int TC = 0;

    cin >> TC;

    for (test_case = 1; test_case <= TC; ++test_case)
    {
        int N = 0;
        int matrix[64][64] = {0,};
        int res = 0;
        list<bool> transIdx;

        cin >> N;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> matrix[i][j];
            }
        }

        for (int j = 1; j < N; j++)
        {
            bool transpos = !(matrix[0][j] == j + 1);

            if (transIdx.empty() == false && transIdx.back() == transpos)
                continue;

            transIdx.push_back(transpos);
        }

        bool isTranspos = transIdx.front();
        transIdx.pop_front();
        if (isTranspos) res = -1;

        while (!transIdx.empty()) {
            isTranspos = transIdx.front();

            if (!isTranspos)
                res += 2;

            transIdx.pop_front();
        }

        if (isTranspos) res += 2;

        cout << res << endl;
    }
    return 0;
}
