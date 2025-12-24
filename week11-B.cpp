#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    int mid;
    cin >> mid;
    maxHeap.push(mid);
    cout << mid << endl;
    for(int i = 1; i <= (n-1)/2; i++){
        int x, y;
        mid = maxHeap.top();
        cin >> x >> y;
        if(x > mid){
            minHeap.push(x);
        } else {
            maxHeap.push(x);
        }
        if(y > mid){
            minHeap.push(y);
        } else {
            maxHeap.push(y);
        }
        if(maxHeap.size() - minHeap.size() == 3){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size() - maxHeap.size() == 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        cout << maxHeap.top() << endl;
    }
    return 0;
}