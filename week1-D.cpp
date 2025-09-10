#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int counter=1;
    while(n!=0 && m!=0){
        cout<<"CASE# "<<counter++<<":"<<endl;
        vector<int> nums(n);
        for(int i=0; i<n; i++){
            cin>>nums[i];
        }
        sort(nums.begin(), nums.end());
        for(int i=0; i<m; i++){
            int query=0;
            cin>>query;
            auto it=lower_bound(nums.begin(), nums.end(), query);
            if(it!=nums.end() && *it==query){
                cout<<query<<" found at "<<(it-nums.begin()+1)<<endl;
            }else{
                cout<<query<<" not found"<<endl;
            }
        }
        cin>>n>>m;
    }
    return 0;
}