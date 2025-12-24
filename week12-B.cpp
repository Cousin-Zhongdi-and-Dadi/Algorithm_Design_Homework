#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct TrieNode {
    bool isEnd;
    int leafCount;
    TrieNode* children[26];
    TrieNode() : isEnd(false), leafCount(0) {
        fill(begin(children), end(children), nullptr);
    }
};

int main() {
    string in;
    TrieNode* root = new TrieNode();
    in = "";
    getline(cin, in);
    while (in != "") {
        TrieNode* curr = root;
        for (char c : in) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
            curr->leafCount++;
        }
        curr->isEnd = true;
        getline(cin, in);
    }
    while (cin >> in) {
        TrieNode* curr = root;
        bool found = true;
        for (char c : in) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                found = false;
                break;
            }
            curr = curr->children[index];
        }
        if (found) {
            cout << curr->leafCount << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}