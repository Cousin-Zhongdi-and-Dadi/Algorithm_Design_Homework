#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V, n;
    cin >> V >> n;
    vector<int> volume(n);
    for(int i = 0; i < n; ++i) {
        cin >> volume[i];
    }
    vector<int> dp(V + 1, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = V; j >= volume[i]; --j) {
            dp[j] = max(dp[j], dp[j - volume[i]] + volume[i]);
        }
    }
    cout << V - dp[V] << '\n';
    return 0;
}