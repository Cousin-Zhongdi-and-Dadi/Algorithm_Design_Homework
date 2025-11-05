#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int caseNum = 1; caseNum <= t; ++caseNum) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        vector<long long> indexes(n + 1, 0);
        vector<long long> dp(n + 1, 0);
        dp[n - 1] = arr[n - 1];
        indexes[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if(dp[i + 1] < 0) {
                dp[i] = arr[i];
                indexes[i] = i;
            } else {
                dp[i] = dp[i + 1] + arr[i];
                indexes[i] = indexes[i + 1];
            }
        }
        long long maxSum = dp[0];
        long long startIndex = 0;
        long long endIndex = indexes[0];
        for (int i = 1; i < n; ++i) {
            if (dp[i] > maxSum) {
                maxSum = dp[i];
                startIndex = i;
                endIndex = indexes[i];
            }
        }
        startIndex++;
        endIndex++;
        cout << "Case " << caseNum << ":\n" << maxSum << " " << startIndex << " " << endIndex << endl << endl;
    }
    return 0;
}