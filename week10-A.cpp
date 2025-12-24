#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
    UnionFind(int n) : parent(n + 1), rank(n + 1, 0) {
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {    
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
private:
    vector<int> parent;
    vector<int> rank;
};

int main(){
    int n, m, p;
    cin >> n >> m >> p;
    UnionFind uf(n+1);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);
    }
    for(int i = 0; i < p; ++i){
        int a, b;
        cin >> a >> b;
        if(uf.find(a) == uf.find(b)){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
