#include <iostream>
#define INF 1e9;
using namespace std;

int dp[310][310];
int m[310];
int sum[310] = {0};
int main() {
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> m[i];
        sum[i] = sum[i-1] + m[i];
    }
    for(int l = 2; l<=n; l++){
        for(int i = 1; i+l-1 <= n; i++){
            int j = i + l - 1;
            dp[i][j] = INF;
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
            }
        }
    }
    cout << dp[1][n] << "\n";
}