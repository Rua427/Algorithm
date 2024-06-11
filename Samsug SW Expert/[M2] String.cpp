#include <iostream>
#include <string>

using namespace std;

int main() {
    int test_case, num;
    int T = 10;
    string strSearch;
    string str;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int result = 0;
        cin >> num;
        cin >> strSearch;
        cin >> str;
        int len = str.length();
        for (int i = 0; i <= len; i++) {
            if (str.compare(i, strSearch.length(), strSearch) == 0) result++;
        }
        cout << '#' << num << ' ' << result << endl;
    }
    return 0;
}
