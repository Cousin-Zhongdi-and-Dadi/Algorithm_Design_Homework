#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef struct Edge {
    vector<int> to;
    vector<int> weight;
}Edge;

void floyd(int n, vector<vector<int>>& dist) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].to.push_back(v);
        edges[u].weight.push_back(w);
        edges[v].to.push_back(u);
        edges[v].weight.push_back(w);
    }
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (size_t j = 0; j < edges[i].to.size(); j++) {
            int v = edges[i].to[j];
            int w = edges[i].weight[j];
            dist[i][v] = min(dist[i][v], w);
        }
    }
    floyd(n, dist);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}