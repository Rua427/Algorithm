#include <iostream>

using namespace std;


void BinaryTree(int *dp, int start, int end, int data) {
    int idx = (start + end) / 2;
    if (start > end || dp[idx] == data) {
        return;
    }

    if (dp[idx] < data) {
        if (dp[idx + 1] >= data) {
            dp[idx + 1] = data;
            return;
        }
        else {
            return BinaryTree(dp, idx + 1, end, data);
        }
    }
    else {
        if (dp[idx - 1] < data) {
            dp[idx] = data;
            return;
        }
        else {
            return BinaryTree(dp, start, idx - 1, data);
        }
    }
}


int main() {


    int length = 0;

    int numTable[1001] = { 0, };
    int dpTable[1001] = { 0, };
  
    int dpIdx = 0;
  

    cin >> length;

    for (int i = 1; i <= length; i++)
    {
        cin >> numTable[i];
    }

    for (int i = 1; i <= length; i++)
    {
        if (dpTable[dpIdx] < numTable[i]) {
            dpTable[++dpIdx] = numTable[i];
        }
        else {
            BinaryTree(dpTable, 1, dpIdx, numTable[i]);
        }
    }

    cout << dpIdx << endl;



    return 0;
}
