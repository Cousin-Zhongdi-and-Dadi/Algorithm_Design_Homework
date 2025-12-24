#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main() {
    int n, m;
    while ( (cin >> n >> m) ) {
        vector<vector<int>> outs(n + 1);
        vector<int> indeg(n + 1, 0);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            outs[a].push_back(b);
            indeg[b]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i <= n; ++i) {
            if (indeg[i] == 0) pq.push(i);
        }

        vector<int> order;
        order.reserve(n);
        while (!pq.empty()) {
            int u = pq.top(); pq.pop();
            order.push_back(u);
            for (int v : outs[u]) {
                if (--indeg[v] == 0) pq.push(v);
            }
        }

        for (int i = 0; i < (int)order.size(); ++i) {
            if (i) cout << ' ';
            cout << order[i];
        }
        cout << '\n';
    }
    return 0;
}