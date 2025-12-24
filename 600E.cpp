#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
vector<int> tree[MAXN + 1];
int color[MAXN + 1];
long long ans[MAXN + 1];

unordered_map<int, int>* dfs(int v, int parent, int &mx, long long &sum) {
    unordered_map<int, int>* cur = new unordered_map<int, int>();
    mx = 0;
    sum = 0;

    for (int u : tree[v]) {
        if (u == parent) continue;

        int child_mx;
        long long child_sum;
        unordered_map<int, int>* child_map = dfs(u, v, child_mx, child_sum);

        if (child_map->size() > cur->size()) {
            swap(cur, child_map);
            mx = child_mx;
            sum = child_sum;
        }

        for (auto &p : *child_map) {
            int c = p.first;
            int cnt = (*cur)[c] += p.second;

            if (cnt > mx) {
                mx = cnt;
                sum = c;
            } else if (cnt == mx) {
                sum += c;
            }
        }

        delete child_map;
    }

    int c = color[v];
    int cnt = ++(*cur)[c];

    if (cnt > mx) {
        mx = cnt;
        sum = c;
    } else if (cnt == mx) {
        sum += c;
    }

    ans[v] = sum;
    return cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    int mx;
    long long sum;
    dfs(1, 0, mx, sum);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
