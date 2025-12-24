#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef struct Edge {
    vector<int> to;
    vector<int> weight;
}Edge;

vector<int> dijkstra(int n, int s, const vector<Edge>& edges) {
    vector<int> dist(n + 1, INT_MAX);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (size_t i = 0; i < edges[u].to.size(); i++) {
            int v = edges[u].to[i];
            int w = edges[u].weight[i];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<Edge> edges(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].to.push_back(v);
        edges[u].weight.push_back(w);
    }
    vector<int> dist = dijkstra(n, s, edges);
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}