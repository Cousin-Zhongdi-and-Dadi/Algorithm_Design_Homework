#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace {
const int mod = 100000000;

inline int add_mod(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

inline int sub_mod(int a, int b) {
    a -= b;
    if (a < 0) a += mod;
    return a;
}
} // namespace

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1, str2;
    cin >> str1 >> str2;
    str1.pop_back();
    str2.pop_back();

    const int n = static_cast<int>(str1.size());
    const int m = static_cast<int>(str2.size());

    vector<int> dp_prev(m + 1, 0), dp_curr(m + 1, 0);
    vector<int> cnt_prev(m + 1, 1), cnt_curr(m + 1, 0); // cnt for row 0 is 1

    for (int i = 1; i <= n; ++i) {
        dp_curr[0] = 0;
        cnt_curr[0] = 1;
        int prev_diag_dp = 0;
        int prev_diag_cnt = 1;
        const char ch = str1[i - 1];
        for (int j = 1; j <= m; ++j) {
            const int up_dp = dp_prev[j];
            const int left_dp = dp_curr[j - 1];
            const int diag_dp = prev_diag_dp;
            const int up_cnt = cnt_prev[j];
            const int left_cnt = cnt_curr[j - 1];
            const int diag_cnt = prev_diag_cnt;

            int best;
            int val = 0;

            if (ch == str2[j - 1]) {
                best = diag_dp + 1;
                val = diag_cnt;
            } else {
                best = up_dp >= left_dp ? up_dp : left_dp;
            }

            if (best == up_dp) val = add_mod(val, up_cnt);
            if (best == left_dp) val = add_mod(val, left_cnt);
            if (ch != str2[j - 1] && best == diag_dp) {
                val = sub_mod(val, diag_cnt);
            }

            dp_curr[j] = best;
            cnt_curr[j] = val;

            prev_diag_dp = up_dp;
            prev_diag_cnt = up_cnt;
        }
        swap(dp_prev, dp_curr);
        swap(cnt_prev, cnt_curr);
    }

    cout << dp_prev[m] << '\n' << cnt_prev[m] << '\n';
    return 0;
}