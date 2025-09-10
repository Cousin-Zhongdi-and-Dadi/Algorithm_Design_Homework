#include<iostream>
using namespace std;

int main(){
    int n,m;

    cin >> n >> m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                sum+=a[i][j];
            }
        }
    }

    cout<<sum<<endl;

    return 0;
}