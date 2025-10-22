#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long l, r, k;
    cin >> l >> r >> k;
    long long cur = 1;
    vector<long long> ans;
    while (cur <= r) {
        if (cur >= l) {
            ans.push_back(cur);
        }
        if (cur > r / k) {
            break;
        }
        cur *= k;
    }
    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        for (size_t i = 0; i < ans.size(); ++i) {
            if (i > 0) {
                cout << " ";
            }
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}