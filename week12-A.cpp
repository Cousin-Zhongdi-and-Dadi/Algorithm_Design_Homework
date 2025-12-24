#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string in, out;
    out = "";
    enum State { LOWER, UPPER, DIGIT };
    State curr = LOWER;
    vector<string> words;
    vector<int> numbers;
    while(cin >> in){
        if(in[0] <= 'Z' && in[0] >= 'A'){
            curr = UPPER;
        } else if (in[0] <= 'z' && in[0] >= 'a'){
            curr = LOWER;
        } else {
            curr = DIGIT;
        }
        words.push_back(in);
        numbers.push_back(curr);
    }
    for (int i = words.size() - 1; i >= 0; i--){
        string temp = words[i];
        if (numbers[i] == UPPER){
            for (int j = 0; j < temp.size(); j++){
                if (temp[j] >= 'A' && temp[j] <= 'Z'){
                    temp[j] = temp[j] - 'A' + 'a';
                }
            }
        } else if (numbers[i] == LOWER){
            for (int j = 0; j < temp.size(); j++){
                if (temp[j] >= 'a' && temp[j] <= 'z'){
                    temp[j] = temp[j] - 'a' + 'A';
                }
            }
        } else {
            reverse(temp.begin(), temp.end());
        }
        out += temp;
        if (i != 0) out += " ";
    }
    cout << out << endl;
    return 0;
}