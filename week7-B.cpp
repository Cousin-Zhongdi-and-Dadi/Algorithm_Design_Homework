#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string str_a, str_b;
    while (cin >> str_a >> str_b) {
        int len_a = str_a.length();
        int len_b = str_b.length();
        vector<vector<int>> dp(len_a + 1, vector<int>(len_b + 1, 0));
        for (int i = 1; i <= len_a; ++i) {
            for (int j = 1; j <= len_b; ++j) {
                if (str_a[i - 1] == str_b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[len_a][len_b] << endl;
    }

    return 0;
}