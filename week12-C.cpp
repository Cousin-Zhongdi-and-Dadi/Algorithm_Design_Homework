#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string target, pattern;
    cin >> target >> pattern;
    vector<int> nxt;
    nxt.resize(pattern.size() + 1);
    nxt[0] = -1;
    int j = -1;
    for (int i = 0; i < pattern.size(); ) {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            nxt[i] = j;
        } else {
            j = nxt[j];
        }
    }
    j = 0;
    for (int i = 0; i < target.size(); ) {
        if (j == -1 || target[i] == pattern[j]) {
            i++;
            j++;
        } else {
            j = nxt[j];
        }
        if (j == pattern.size()) {
            cout << i - j + 1 << endl;
            j = nxt[j];
        }
    }
    for (int i = 1; i <= pattern.size(); i++) {
        cout << nxt[i] << " ";
    }
    cout << endl;
    return 0;
}