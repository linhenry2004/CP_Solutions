#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
int cnt = 0;
int X[maxn];
int trie[30 * maxn][2];

void update (int p, int x, int d) {
    if (d < 0) {
        return;
    }
    int c = (x >> d) & 1;
    if (!trie[p][c]) {
        trie[p][c] = ++cnt;
    }
    update(trie[p][c], x, d - 1);
}

int query (int p, int x, int d) {
    if (d < 0) {
        return x;
    }
    int c = ((x >> d) & 1) ^ 1;
    if (!trie[p][c]) {
        c ^= 1;
    }
    return query(trie[p][c], x, d - 1) ^ (c << d);
}

int run (int n) {
    int x = 0, ans = 0;
    update(0, 0, 30);
    for (int i = 1; i <= n; i++) {
        x ^= X[i];
        ans = max(ans, query(0, x, 30));
        update(0, x, 30);
    }
    return ans;
}

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> X[i];
    }
    cout << run(n) << endl;
    return 0;
}