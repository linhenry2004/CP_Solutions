#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* lc;
    Node* rc;

    Node(): val(0) {}
    Node(int x): val(x) {}
};

Node* build (vector<int> &a, int l, int r) {
    if (r - l == 1) {
        return new Node(a[l]);
    }
    
    Node* ptr = new Node();

    int mid = (l + r) / 2;
    ptr->lc = build(a, l, mid);
    ptr->rc = build(a, mid, r);

    ptr->val = (ptr->lc->val + ptr->rc->val);
    return ptr;
}

int query (Node* ptr, int ql, int qr, int l, int r) {
    if (l >= ql && r <= qr) {
        return ptr->val;
    }
    if (r <= ql || l >= qr) {
        return 0;
    }
    
    int mid = (l + r) / 2;
    int x1 = query(ptr->lc, ql, qr, l, mid);
    int x2 = query(ptr->rc, ql, qr, mid, r);
    return (x1 + x2);
}

void update (Node* ptr, int a, int b, int l, int r) {
    if (r <= a || l > a) {
        return;
    }
    if (r - l == 1 && l == a) {
        ptr->val = b;
        return;
    }

    int mid = (l + r) / 2;
    update(ptr->lc, a, b, l, mid);
    update(ptr->rc, a, b, mid, r);
    ptr->val = (ptr->lc->val + ptr->rc->val);
}

int main () {
    int n, q;
    cin >> n >> q;
    set<int> s;
    vector<int> a(n), nxt(n, -1);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (s.count(x)) {
            a[i] = 0;
            nxt[mp[x]] = i;
            mp[x] = i;
        } else {
            a[i] = 1;
            mp[x] = i;
        }
        s.insert(x);
    }

    Node* tree = build(a, 0, n);

    vector<pair<pair<int, int>, int>> ranges;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        ranges.push_back({{x, y}, i});
    }
    sort(ranges.begin(), ranges.end());

    int l = 0;
    vector<int> ans(q);
    for (auto r : ranges) {
        int u = r.first.first;
        int v = r.first.second;
        while (l < u) {
            if (nxt[l] != -1) {
                update(tree, nxt[l], 1, 0, n);
            }
            l++;
        }
        ans[r.second] = query(tree, u, v, 0, n);
    }

    for (int i : ans) {
        cout << i << endl;
    }
    
    return 0;
}