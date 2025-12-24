#include <bits/stdc++.h>
using namespace std;

struct Node {
    char c;
    int len, sz, pr;
    Node *l, *r;
    Node(char _c, int _len)
        : c(_c), len(_len), sz(_len), pr(rand()), l(nullptr), r(nullptr) {}
};

int getsz(Node* t) {
    return t ? t->sz : 0;
}

void pull(Node* t) {
    if (!t) return;
    t->sz = t->len + getsz(t->l) + getsz(t->r);
}

Node* merge(Node* a, Node* b) {
    if (!a || !b) return a ? a : b;
    if (a->pr > b->pr) {
        a->r = merge(a->r, b);
        pull(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}

// split by first k characters
void split(Node* t, int k, Node* &a, Node* &b) {
    if (!t) {
        a = b = nullptr;
        return;
    }
    if (getsz(t->l) >= k) {
        split(t->l, k, a, t->l);
        b = t;
    } else if (getsz(t->l) + t->len <= k) {
        split(t->r, k - getsz(t->l) - t->len, t->r, b);
        a = t;
    } else {
        int leftLen = k - getsz(t->l);
        Node* left = new Node(t->c, leftLen);
        Node* right = new Node(t->c, t->len - leftLen);
        left->l = t->l;
        right->r = t->r;
        pull(left);
        pull(right);
        a = left;
        b = right;
    }
    pull(t);
}

void collect(Node* t, vector<int>& cnt) {
    if (!t) return;
    collect(t->l, cnt);
    cnt[t->c - 'a'] += t->len;
    collect(t->r, cnt);
}

Node* build(const vector<int>& cnt, bool inc) {
    Node* res = nullptr;
    if (inc) {
        for (int i = 0; i < 26; i++)
            if (cnt[i])
                res = merge(res, new Node('a' + i, cnt[i]));
    } else {
        for (int i = 25; i >= 0; i--)
            if (cnt[i])
                res = merge(res, new Node('a' + i, cnt[i]));
    }
    return res;
}

void output(Node* t) {
    if (!t) return;
    output(t->l);
    for (int i = 0; i < t->len; i++)
        cout << t->c;
    output(t->r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    Node* root = nullptr;
    for (char c : s)
        root = merge(root, new Node(c, 1));

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        Node *a, *b, *c;
        split(root, r, b, c);
        split(b, l - 1, a, b);

        vector<int> cnt(26, 0);
        collect(b, cnt);

        Node* mid = build(cnt, k == 1);
        root = merge(merge(a, mid), c);
    }

    output(root);
    cout << "\n";
    return 0;
}
