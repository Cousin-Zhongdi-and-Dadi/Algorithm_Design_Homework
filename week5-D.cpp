#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> cards(n);
    int sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> cards[i];
        sum += cards[i];
    }
    int average = sum / n;
    int moves = 0;
    int left = 0, right = n - 1;
    while(cards[left] == average && left < right) ++left;
    while(cards[right] == average && left < right) --right;
    while(left < right){
        if(cards[left] != average){
            moves++;
            cards[left + 1] += cards[left] - average;
        }
        left++;
    }
    cout << moves << endl;
    return 0;
}