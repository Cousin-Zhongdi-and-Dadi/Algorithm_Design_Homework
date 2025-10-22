#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Stall{
    int start;
    int end;
    int index;
};

struct Cow{
    int start;
    int end;
    int stallIndex;
};

int main(){
    int n;
    cin >> n;
    vector<Cow> cows(n);
    for(int i = 0; i < n; ++i){
        cin >> cows[i].start >> cows[i].end;
    }
    vector<Stall> stalls;
    stalls.push_back({cows[0].start, cows[0].end, 1});
    cows[0].stallIndex = 1;
    for(int i = 1; i < n; ++i){
        bool placed = false;
        for(auto &stall : stalls){
            if(cows[i].start > stall.end){
                stall.end = cows[i].end;
                placed = true;
                cows[i].stallIndex = stall.index;
                break;
            }
        }
        if(!placed){
            cows[i].stallIndex = (int)stalls.size() + 1;
            stalls.push_back({cows[i].start, cows[i].end, (int)stalls.size() + 1});
        }
    }
    cout << stalls.size() << endl;
    for(int i = 0; i < n; ++i){
        cout << cows[i].stallIndex << endl;
    }
    return 0;
}