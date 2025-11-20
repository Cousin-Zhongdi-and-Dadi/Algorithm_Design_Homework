#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check(const vector<vector<char> >& grid, int w, int h, int x, int y) {
    if(grid[y][x] == '#') return false;
    else return true;
}

int bfs(const vector<vector<char> >& grid, int w, int h, int x, int y) {
    queue<pair<int,int> > que;
    que.push(pair<int,int>(x, y));
    vector<vector<bool> > visited(h, vector<bool>(w, false));
    visited[y][x] = true;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    while(!que.empty()) {
        pair<int,int> cur = que.front();
        int cx = cur.first;
        int cy = cur.second;
        que.pop();
        for(int dir = 0; dir < 4; ++dir) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(nx >= 0 && nx < w && ny >= 0 && ny < h) {
                if(!visited[ny][nx] && check(grid, w, h, nx, ny)) {
                    visited[ny][nx] = true;
                    que.push(pair<int,int>(nx, ny));
                }
            }
        }
    }
    int counter = 0;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(visited[i][j]) counter++;
        }
    }
    return counter;
}

int main() {
    int w, h;
    cin >> w >> h;
    while(w != 0 && h != 0) {
        vector<vector<char> > grid(h, vector<char>(w));
        int start_x = 0, start_y = 0;
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                cin >> grid[i][j];
                if(grid[i][j] == '@') {
                    start_x = j;
                    start_y = i;
                }
            }
        }
        int counter = bfs(grid, w, h, start_x, start_y);
        cout << counter << endl;
        cin >> w >> h;
    }
}