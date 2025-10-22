#include <iostream>
#include <vector>

using namespace std;

int count = 0;
void chessBoard(vector<vector<int>>& board, int c, int r, int x, int y, int size) {
    if (size == 1) return;
    int t = ++count;
    int s = size / 2;
    int midX = c + s - 1;
    int midY = r + s - 1;
    if (x <= midX && y <= midY) {
        chessBoard(board, c, r, x, y, s);
    } else {
        board[midX][midY] = t;
        chessBoard(board, c, r, midX, midY, s);
    }
    if (x <= midX && y > midY) {
        chessBoard(board, c, r + s, x, y, s);
    } else {
        board[midX][midY + 1] = t;
        chessBoard(board, c, r + s, midX, midY + 1, s);
    }
    if (x > midX && y <= midY) {
        chessBoard(board, c + s, r, x, y, s);
    } else {
        board[midX + 1][midY] = t;
        chessBoard(board, c + s, r, midX + 1, midY, s);
    }
    if (x > midX && y > midY) {
        chessBoard(board, c + s, r + s, x, y, s);
    } else {
        board[midX + 1][midY + 1] = t;
        chessBoard(board, c + s, r + s, midX + 1, midY + 1, s);
    }
}

int main() {
    int n;
    cin >> n;
    n = 1 << n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    int x, y;
    cin >> x >> y;
    x = x - 1;
    y = y - 1;
    chessBoard(board, 0, 0, x, y, n);
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}