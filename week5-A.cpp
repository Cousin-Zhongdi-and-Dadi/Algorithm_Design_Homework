#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> apples;
    int effort = 0;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        apples.push(a);
    }
    while(apples.size() > 1){
        int a = apples.top(); apples.pop();
        int b = apples.top(); apples.pop();
        int c = a + b;
        effort += c;
        apples.push(c);
    }
    cout << effort << endl;
}