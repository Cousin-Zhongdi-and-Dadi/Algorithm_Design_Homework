#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("\n");
        return 0;
    }
    vector<int> a(n + 1);
    vector<int> f(n + 1, 0);
    stack<int> s;
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i=n; i>=1; i--) {
        while (!s.empty() && a[s.top()] <= a[i]) {
            s.pop();
        }
        if (!s.empty()) {
            f[i] = s.top();
        } else {
            f[i] = 0;
        }
        s.push(i);
    }
    // 高效输出（用 printf）
    for (int i = 1; i <= n; i++) {
        printf("%d", f[i]);
        if (i != n) printf(" ");
        else printf("\n");
    }
    return 0;
}