#include <iostream>
#include <vector>
using namespace std;

struct Milk {
    int start;
    int end;
    int efficiency;
};

int main(){
    int N, M, R;
    if (!(cin >> N >> M >> R)) return 0;

    // Group intervals by their start time to process in O(N + M)
    vector<vector<Milk> > byStart(N + 1);
    for (int i = 0; i < M; ++i) {
        Milk milk;
        cin >> milk.start >> milk.end >> milk.efficiency;
        if (milk.start < 0) milk.start = 0;
        if (milk.end > N) milk.end = N;
        if (milk.start <= N) {
            byStart[milk.start].push_back(milk);
        }
    }

    // dp[t] = maximum milk achievable by time t (t in [0..N])
    vector<long long> dp(N + 1, 0);

    for (int t = 0; t <= N; ++t) {
        // carry forward best value
        if (t > 0) dp[t] = max(dp[t], dp[t-1]);

        // try starting any interval at time t
        if (t <= N - 1) {
            for (size_t i = 0; i < byStart[t].size(); ++i) {
                const Milk& milk = byStart[t][i];
                int newt = milk.end + R; // earliest time when next milking can start
                if (newt > N) newt = N;
                dp[newt] = max(dp[newt], dp[t] + milk.efficiency);
            }
        }
    }

    cout << dp[N] << '\n';
    return 0;
}