#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<string> s;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        s.insert(str);
    }
    cout << s.size() << endl;
}