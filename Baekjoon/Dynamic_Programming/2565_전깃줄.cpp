#include <iostream>
#include <cmath>
using namespace std;


int BinaryTree(int *dp, int start, int end, int data) {
    int idx = (start + end) / 2;
    if (start > end || dp[idx] == data) {
        return idx;
    }

    if (dp[idx] < data) {
        if (dp[idx + 1] >= data) {
            dp[idx + 1] = data;
            return idx + 1;
        }
        else {
            return BinaryTree(dp, idx + 1, end, data);
        }
    }
    else {
        if (dp[idx - 1] < data) {
            dp[idx] = data;
            return idx;
        }
        else {
            return BinaryTree(dp, start, idx - 1, data);
        }
    }
}


int main() {
    int length = 0;

    int tempTable[501] = { 0, };

    int numTable[501] = { 0, };
    int num2Table[501] = { 0, };
    int lenTable[501] = { 0, };

    int dpTable[501] = { 0, };
    int dpIdx = 0;

    int result = 0;

    cin >> length;

    for (int i = 1; i <= length; i++)
    {
        int a, b;
        cin >> a >> b;
        tempTable[a] = b;
    }
    int idx = 1;
    for (int i = 1; i <= 500; i++)
    {
        if (tempTable[i] != 0) {
            numTable[idx] = i;
            num2Table[idx] = tempTable[i];
            ++idx;
        }
    }

    for (int i = 1; i <= length; i++)
    {
        if (dpTable[dpIdx] < numTable[i]) {
            dpTable[++dpIdx] = numTable[i];
            lenTable[i] = dpIdx;
        }
        else {
            lenTable[i] = BinaryTree(dpTable, 1, dpIdx, numTable[i]);
        }
    }

    
    for (int i = 1; i <= length; i++)
    {
        lenTable[i] = 0;
        dpTable[i] = 0;
    }
    result += dpIdx;
    dpIdx = 0;


    for (int i = 1; i <= length; i++)
    {
        if (dpTable[dpIdx] < num2Table[i]) {
            dpTable[++dpIdx] = num2Table[i];
            lenTable[i] = dpIdx;
        }
        else {
            lenTable[i] = BinaryTree(dpTable, 1, dpIdx, num2Table[i]);
        }
    }
    
    result -= dpIdx;

    cout << abs(result) << endl;

    return 0;
}
