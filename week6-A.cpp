#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static string addBig(const string &x, const string &y) {
    string a = x;
    string b = y;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string res;
    int carry = 0;
    size_t n = max(a.size(), b.size());
    for (size_t i = 0; i < n; ++i) {
        int da = (i < a.size()) ? (a[i] - '0') : 0;
        int db = (i < b.size()) ? (b[i] - '0') : 0;
        int s = da + db + carry;
        res.push_back(char('0' + (s % 10)));
        carry = s / 10;
    }
    if (carry) res.push_back(char('0' + carry));
    reverse(res.begin(), res.end());
    // remove leading zeros (shouldn't be any except "0")
    size_t pos = res.find_first_not_of('0');
    if (pos == string::npos) return "0";
    return res.substr(pos);
}

int main() {
    long long n;
    if (!(cin >> n) || n < 0) return 0;
    if (n == 0) { cout << 0 << '\n'; return 0; }
    if (n == 1) { cout << 1 << '\n'; return 0; }

    string a = "1", b = "1";
    for (long long i = 2; i <= n; ++i) {
        string c = addBig(a, b);
        a = b;
        b = c;
    }
    cout << b << '\n';
}