#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    while (n){
        map<int, int> monk;
        monk[1000000000] = 1;
        for(int i = 0; i < n; i++){
            int id, power, ans;
            cin >> id >> power;
            monk[power] = id;
            auto it = monk.find(power);
            if(it == monk.begin()){
                ans = next(it)->second;
            } else {
                int left = prev(it)->first;
                int right = next(it)->first;
                if(power - left <= right - power){
                    ans = monk[left];
                } else {
                    ans = monk[right];
                }
            }
            cout << id << " " << ans << endl;
        }
        cin >> n;
    }
    return 0;
}