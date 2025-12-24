#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int isOula(vector<vector<int>>& ins, vector<vector<int>>& outs, int n) {
    int start_nodes = 0, end_nodes = 0;
    for (int i = 1; i <= n; ++i) {
        if ((ins[i].size() - outs[i].size() != 0)) {
            if (ins[i].size() - outs[i].size() == 1) {
                end_nodes++;
            } else if (outs[i].size() - ins[i].size() == 1) {
                start_nodes++;
            } else {
                return 0;
            }
        }
    }
    return (start_nodes == 1 && end_nodes == 1) || (start_nodes == 0 && end_nodes == 0);
}

void eulerianPath(vector<int> &path, vector<vector<int>>& outs, int n, int start) {
    vector<int> stack;
    vector<int> out_index(n + 1, 0);
    stack.push_back(start);

    while (!stack.empty()) {
        int u = stack.back();
        if (out_index[u] < (int)outs[u].size()) {
            stack.push_back(outs[u][out_index[u]]);
            out_index[u]++;
        } else {
            path.push_back(u);
            stack.pop_back();
        }
    }
    reverse(path.begin(), path.end());
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ins(n + 1);
    vector<vector<int>> outs(n + 1);
    int edges_read = 0;
    for (int i = 0; i < m; ++i) {
        int a, b;
        if (!(cin >> a >> b)) break;
        outs[a].push_back(b);
        ins[b].push_back(a);
        edges_read++;
    }
    for (int i = 1; i <= n; ++i) {
        if (!outs[i].empty()) {
            sort(outs[i].begin(), outs[i].end());
        }
    }
    if (!isOula(ins, outs, n)) {
        cout << "No" << endl;
        return 0;
    } 
    vector<int> path;
    int start = 1;
    bool found = false;
    for (int i = 1; i <= n; ++i) {
        if ((int)outs[i].size() - (int)ins[i].size() == 1) {
            start = i;
            found = true;
            break;
        }
    }
    if (!found) {
        for (int i = 1; i <= n; ++i) if (!outs[i].empty()) { start = i; break; }
    }

    eulerianPath(path, outs, n, start);
    if (path.size() != (size_t)edges_read + 1) {
        cout << "No" << endl;
    } else {
        for (int i = 0; i < path.size(); ++i) {
            if (i) cout << ' ';
            cout << path[i];
        }
        cout << endl;
    }
    return 0;
}