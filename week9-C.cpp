#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct State {
    int x, y;
    int keys;
    int time;
};

int bfs(int start_x, int start_y, int n, int m, int t, char maze[21][21]) {
    const int MAXK = 1 << 10; // a-j
    static bool vis[21][21][1 << 10];
    // reset visited
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < MAXK; ++k)
                vis[i][j][k] = false;

    queue<State> q;
    q.push(State{start_x, start_y, 0, 0});
    vis[start_x][start_y][0] = true;

    while (!q.empty()) {
        State cur = q.front(); q.pop();
        // try 4 directions
        for (int d = 0; d < 4; ++d) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            int ntime = cur.time + 1;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            char ch = maze[nx][ny];
            if (ch == '*') continue; // wall
            // If move reaches exit, must be strictly before t
            if (ch == '^') {
                if (ntime < t) return ntime;
                else continue;
            }
            int nkeys = cur.keys;
            if (ch >= 'a' && ch <= 'j') {
                nkeys |= (1 << (ch - 'a'));
            }
            if (ch >= 'A' && ch <= 'J') {
                int need = 1 << (ch - 'A');
                if ((cur.keys & need) == 0) continue; // locked, don't have key
            }
            // can only enqueue if still possible to reach exit before inspections:
            // further moves will increase time; if ntime >= t then no chance (must reach exit < t)
            if (ntime >= t) continue;
            if (!vis[nx][ny][nkeys]) {
                vis[nx][ny][nkeys] = true;
                q.push(State{nx, ny, nkeys, ntime});
            }
        }
    }
    return -1;
}

int main() {
    int n, m, t;
    while (cin >> n >> m >> t) {
        int start_x = 0, start_y = 0;
        char maze[21][21];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> maze[i][j];
                if (maze[i][j] == '@') {
                    start_x = i;
                    start_y = j;
                }
            }
        }
        int ans = bfs(start_x, start_y, n, m, t, maze);
        cout << ans << endl;
    }
    return 0;
}