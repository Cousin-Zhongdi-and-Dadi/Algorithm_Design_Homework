#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

string d = "durl";

struct node{
    string state;
    int cantor;
    int pos;
    node(string s, int c, int p): state(s), cantor(c), pos(p) {}
};

struct path{
    int from;
    char dir;
}pa[362888];

bool legal(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

int visited[362888] = {0};
int factory[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int getCantor(string s) {
    int cantor = 0;
    for (int i = 0; i < 9; ++i) {
        int cnt = 0;
        for (int j = i + 1; j < 9; ++j) {
            if (s[j] < s[i]) cnt++;
        }
        cantor += cnt * factory[8 - i];
    }
    return cantor;
}

void bfs(string init) {
    queue<node> q;
    int cantor = getCantor(init);
    q.push(node(init, cantor, 8));
    visited[cantor] = 1;
    pa[cantor].from = -1;
    while (!q.empty()) {
        node cur = q.front(); q.pop();
        int pos = cur.pos;
        int x = pos / 3;
        int y = pos % 3;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (!legal(nx, ny)) 
                continue;
            int move = nx * 3 + ny;
            string nextState = cur.state;
            swap(nextState[pos], nextState[move]);
            cantor = getCantor(nextState);
            if (visited[cantor])
                continue;
            visited[cantor] = 1;
            q.push(node(nextState, cantor, move));
            pa[cantor].from = cur.cantor;
            pa[cantor].dir = d[i];
        }
    }
}

int main() {
    bfs("12345678x");
    string tmp;
    while(getline(cin, tmp)) {
        string puzzle = "";
        int pos = 0;
        for (int i = 0; i < tmp.size(); ++i) {
            if (tmp[i] != ' ') {
                puzzle.push_back(tmp[i]);
            }
        }
        int num = getCantor(puzzle);
        if (visited[num] == 0) {
            cout << "unsolvable\n";
            continue;
        }
        while(true){
            if(pa[num].from == -1) break;
            cout << pa[num].dir;
            num = pa[num].from;
        }
        cout << "\n";
    }
    return 0;
}