#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs_stack(const vector<vector<int>>& g, int start, vector<char>& vis) {
    stack<int> st;
    st.push(start);
    vis[start] = 1;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                st.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    while ( (cin >> n >> m) ) {
        if (n == 0 && m == 0) break;
        vector<vector<int>> outs(n + 1), ins(n + 1);
        for (int i = 0; i < m; ++i) {
            int a, b; cin >> a >> b;
            outs[a].push_back(b);
            ins[b].push_back(a);
        }
        vector<char> vis(n + 1, 0);
        dfs_stack(outs, 1, vis);
        bool ok = true;
        for (int i = 1; i <= n; ++i) if (!vis[i]) { ok = false; break; }
        if (!ok) {
            cout << "No\n";
            continue;
        }
        fill(vis.begin(), vis.end(), 0);
        dfs_stack(ins, 1, vis);
        for (int i = 1; i <= n; ++i) if (!vis[i]) { ok = false; break; }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}