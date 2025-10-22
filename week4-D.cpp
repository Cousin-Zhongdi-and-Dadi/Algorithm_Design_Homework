#include <iostream>
#include <string>
using namespace std;

int transformCost(const string &s, int l, int r, char target) {
    if (r - l == 1) {
        return s[l] != target ? 1 : 0;
    }
    int mid = (l + r) / 2;
    int leftCost = transformCost(s, l, mid, target + 1);
    int rightCost = transformCost(s, mid, r, target + 1);
    int costLeftAll = 0;
    for (int i = l; i < mid; ++i) {
        if (s[i] != target) ++costLeftAll;
    }
    int costRightAll = 0;
    for (int i = mid; i < r; ++i) {
        if (s[i] != target) ++costRightAll;
    }
    int cost1 = costLeftAll + rightCost;
    int cost2 = costRightAll + leftCost;
    return min(cost1, cost2);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int len;
        string s;
        cin >> len >> s;
        cout << transformCost(s, 0, len, 'a') << endl;
    }
}