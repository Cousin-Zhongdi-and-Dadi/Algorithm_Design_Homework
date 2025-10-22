#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int times;
    if(!(cin >> times)) return 0;
    while(times--){
        int n, V, W;
        cin >> n >> V >> W;
        vector<int> pills(n);
        for(int i = 0; i < n; i++) cin >> pills[i];
        sort(pills.begin(), pills.end());
        long long sumP = 0; // sum of selected Pi (percent)
        int k = 0; // count of selected bottles
        for(int i = 0; i < n; i++){
            if(sumP + pills[i] <= (long long)(k + 1) * W){
                sumP += pills[i];
                k++;
            }
        }
        if(k == 0){
            cout << "0 0.00" << endl;
        }else{
            int volume = k * V;
            double avgPercent = (double)sumP / k; // 平均百分比
            double conc = avgPercent / 100.0; // 输出为小数（例如 0.23）
            cout << volume << " " << fixed << setprecision(2) << conc << endl;
        }
    }
    return 0;
}