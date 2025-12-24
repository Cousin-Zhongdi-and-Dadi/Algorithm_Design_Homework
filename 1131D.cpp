#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        while (x != fa[x]) {
            fa[x] = fa[fa[x]];
            x = fa[x];
        }
        return x;
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) fa[y] = x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int N = n + m;
    DSU dsu(N);

    // 1. Handle '='
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '=') {
                dsu.unite(i, n + j);
            }
        }
    }

    // 2. Build graph
    vector<vector<int>> g(N);
    vector<int> indeg(N, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = dsu.find(i);
            int v = dsu.find(n + j);
            if (a[i][j] == '<') {
                if (u == v) {
                    cout << "No\n";
                    return 0;
                }
                g[u].push_back(v);
                indeg[v]++;
            }
            if (a[i][j] == '>') {
                if (u == v) {
                    cout << "No\n";
                    return 0;
                }
                g[v].push_back(u);
                indeg[u]++;
            }
        }
    }

    // 3. Topological sort + DP
    vector<int> dp(N, 1);
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (dsu.find(i) == i && indeg[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cnt++;
        for (int v : g[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            if (--indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    // 检查是否有环
    for (int i = 0; i < N; i++) {
        if (dsu.find(i) == i && indeg[i] > 0) {
            cout << "No\n";
            return 0;
        }
    }

    // 4. Output
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        cout << dp[dsu.find(i)] << " ";
    }
    cout << "\n";
    for (int j = 0; j < m; j++) {
        cout << dp[dsu.find(n + j)] << " ";
    }
    cout << "\n";

    return 0;
}
