#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int best_global;
int total_sum;
vector<int> arr;

void dfs_search(int idx, int sumA, int rem) {
    if (idx == (int)arr.size()) {
        best_global = min(best_global, max(sumA, total_sum - sumA));
        return;
    }
    // 剪枝：当前 A 已经不可能获得更优解
    if (sumA >= best_global) return;
    // 剪枝：即使把剩下所有题都放到 A，B 的最小可能和仍 >= best
    if (total_sum - (sumA + rem) >= best_global) return;

    int val = arr[idx];
    // 把当前题放到 A
    dfs_search(idx + 1, sumA + val, rem - val);
    // 把当前题放到 B
    dfs_search(idx + 1, sumA, rem - val);
}

int min_time_for_subject(vector<int> times) {
    arr = times;
    sort(arr.begin(), arr.end(), greater<int>()); // 大的先试，有利剪枝
    total_sum = accumulate(arr.begin(), arr.end(), 0);
    int rem = total_sum;
    best_global = total_sum; // 初始上界：把所有题放同一组
    dfs_search(0, 0, rem);
    return best_global;
}

int main() {
    int s1, s2, s3, s4;
    if (!(cin >> s1 >> s2 >> s3 >> s4)) return 0;
    vector<int> subject1(s1), subject2(s2), subject3(s3), subject4(s4);
    for (int i = 0; i < s1; ++i) cin >> subject1[i];
    for (int i = 0; i < s2; ++i) cin >> subject2[i];
    for (int i = 0; i < s3; ++i) cin >> subject3[i];
    for (int i = 0; i < s4; ++i) cin >> subject4[i];

    long long ans = 0;
    ans += min_time_for_subject(subject1);
    ans += min_time_for_subject(subject2);
    ans += min_time_for_subject(subject3);
    ans += min_time_for_subject(subject4);

    cout << ans << "\n";
    return 0;
}