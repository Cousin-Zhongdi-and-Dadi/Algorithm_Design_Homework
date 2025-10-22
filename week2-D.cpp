#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> spells;
    vector<string> descs;
    unordered_map<string, int> spellIdx; // spell -> index

    spells.reserve(100000);
    descs.reserve(100000);
    spellIdx.reserve(100000);

    string line;
    // 读取词典部分直到 "@END@"
    while (getline(cin, line)) {
        if (line == "@END@") break;
        if (line.empty()) continue;
        size_t rb = line.find(']');
        if (rb == string::npos) continue;
        string spell;
        if (rb >= 1 && line[0] == '[') spell = line.substr(1, rb - 1);
        else spell = line.substr(0, rb);
        string desc;
        if (rb + 2 <= line.size()) desc = line.substr(rb + 2);
        else desc = "";

        int idx = (int)spells.size();
        spells.push_back(std::move(spell));
        descs.push_back(std::move(desc));
        spellIdx[spells[idx]] = idx;
    }

    // 读整数 N（可能有空行）
    int N = 0;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        try {
            N = stoi(line);
            break;
        } catch (...) {
            continue;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (!getline(cin, line)) break;
        if (line.empty()) {
            cout << "what?\n";
            continue;
        }
        if (line.front() == '[' && line.back() == ']') {
            string key = line.substr(1, line.size() - 2);
            auto it = spellIdx.find(key);
            if (it != spellIdx.end()) cout << descs[it->second] << '\n';
            else cout << "what?\n";
        } else {
            // 线性查找描述对应的咒语（N<=1000，允许线性扫描）
            bool found = false;
            for (size_t j = 0; j < descs.size(); ++j) {
                if (descs[j] == line) {
                    cout << spells[j] << '\n';
                    found = true;
                    break;
                }
            }
            if (!found) cout << "what?\n";
        }
    }
    return 0;
}