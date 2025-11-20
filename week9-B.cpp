#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maze[45][45];
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dst[45][45];
int vst[45][45];

bool is_valid(int r, int c, int rows, int cols) {
    return r > 0 && r <= rows && c > 0 && c <= cols;
}

int dbfs(int r, int c) {
    bool flag = true;
    q1.push({1, 1}); dst[1][1] = 1; vst[1][1] = 1;
    q2.push({r, c}); dst[r][c] = 1; vst[r][c] = 2;
    while (!q1.empty() && !q2.empty()) {
        int x0, y0;
        if(q1.size() <= q2.size()) {
            x0 = q1.front().first;
            y0 = q1.front().second;
            q1.pop();
            flag = 0;
        } else {
            x0 = q2.front().first;
            y0 = q2.front().second;
            q2.pop();
            flag = 1;
        }
        for (int i = 0; i < 4; ++i) {
            int x = x0 + dx[i];
            int y = y0 + dy[i];
            if (is_valid(x, y, r, c) && maze[x][y] == 0) {
                if(!dst[x][y]){
                    dst[x][y] = dst[x0][y0] + 1;
                    vst[x][y] = vst[x0][y0];
                    if (flag) {
                        q2.push({x, y});
                    } else {
                        q1.push({x, y});
                    }
                } else if (vst[x0][y0] + vst[x][y] == 3) {
                    return dst[x0][y0] + dst[x][y];
                }
            }
        }
    }
    return -1;
}

int main() {
    int r, c;
    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            char cell;
            cin >> cell;
            maze[i][j] = (cell == '#') ? 1 : 0;
        }
    }
    int ans = dbfs(r, c);
    cout << ans << endl;
    return 0;
}