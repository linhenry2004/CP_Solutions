#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 2e5 + 1;
int bit[maxn], s[maxn];

void update (int p, int x) {
    for (; p < maxn; p += p & -p) {
        bit[p] += x;
    }
}

int query (int p) {
    int sum = 0;
    for (; p > 0; p -= p & -p) {
        sum += bit[p];
    }
    return sum;
}

int32_t main () {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        update(i, s[i]);
    }

    while (q--) {
        int t, a, b; 
        cin >> t >> a >> b; 
        if (t == 1) {
            update(a, b - s[a]);
            s[a] = b;
        } else {
            cout << query(b) - query(a - 1) << endl;
        }
    }
    return 0;
}