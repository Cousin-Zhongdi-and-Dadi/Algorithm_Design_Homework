#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    while(n--){
        int isErased = 0;
        for(int i = 0; i < s.length() - 1; i++){
            if(s[i] > s[i + 1]){
                s.erase(i, 1);
                isErased = 1;
                break;
            }
        }
        if(!isErased){
            s.erase(s.length() - 1, 1);
        }
    }
    size_t p = 0;
    while(p < s.size() && s[p] == '0') ++p;
    s = s.substr(p);
    if(s.empty()) s = "0";

    cout << s << endl;
    return 0;
}