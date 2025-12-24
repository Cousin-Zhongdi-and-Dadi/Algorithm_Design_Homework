#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 50010;
int n, k, ans = 0;
int fa[maxn*3];

int find(int x){
    return x==fa[x]? x:find(fa[x]);
}

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n*3; ++i){
        fa[i] = i;
    }
    while(k--){
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if(x > n || y > n){
            ans++;
            continue;
        }
        if(op == 1){
            if(find(x) == find(y + n) || find(x) == find(y + 2*n)){
                ans++;
            } else {
                fa[find(y)] = find(x);
                fa[find(y + n)] = find(x + n);
                fa[find(y + 2*n)] = find(x + 2*n);
            }
        } else {
            if(find(x) == find(y) || find(x) == find(y + 2*n)){
                ans++;
            } else {
                fa[find(x)] = find(y + n);
                fa[find(x + n)] = find(y + 2*n);
                fa[find(x + 2*n)] = find(y);
            }
        }
    }
    cout << ans << endl;
    return 0;
}