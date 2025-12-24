#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        q.push(x);
    }
    while(!q.empty()){
        printf("%d ", q.top());
        q.pop();
    }
    return 0;
}