#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dr = {-2, -2, -1, -1, 1, 1, 2, 2};
vector<int> dc = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    int n, m, x, y;
    if (!(cin >> n >> m >> x >> y)) return 0;
    int sr = x - 1;
    int sc = y - 1;

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;
    dist[sr][sc] = 0;
    q.push({sr, sc});

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int i = 0; i < 8; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j) cout << " ";
            cout << dist[i][j];
        }
        cout << "\n";
    }
    return 0;
}