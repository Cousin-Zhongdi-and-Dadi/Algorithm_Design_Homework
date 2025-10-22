#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    vector<vector<int>> result;
    for(int i=0;i<(1<<n);i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)) count++;
        }
        if(count==r){
            vector<int> temp;
            for(int k=0;k<n;k++){
                if(i&(1<<k)) temp.push_back(k+1);
            }
            result.push_back(temp);
        }
    }
    sort(result.begin(),result.end(),[](const vector<int>& a,const vector<int>& b){
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])
                return a[i]<b[i];
        }
        return a.size()<b.size();
    });
    for(auto v:result){
        for (auto x : v) {
            cout<<setw(3)<<x;
        }
        cout << endl;
    }
}