#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n != 0){
        vector<pair<int, int>> tvs;
        for(int i = 0; i < n; ++i){
            int start, stop;
            cin >> start >> stop;
            tvs.push_back({stop, start});
        }
        int count = 1;
        sort(tvs.begin(), tvs.end());
        int tmp = 0;
        for(int i = 1; i < n; ++i){
            if(tvs[i].second >= tvs[tmp].first){
                count++;
                tmp = i;
            }
        }
        cout << count << endl;
        cin >> n;
    }
}