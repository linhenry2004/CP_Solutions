#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct ooo {
    int l, r, t;
};

const int maxn = 2e5 + 1;
int X[maxn], ans[maxn], P[maxn];
int S[2 * maxn];
int T[20][maxn];
vector<ooo> Q;

int highbit (int x) {
    int p = 0;
    for (int i = 4; i >= 0; i--) {
        if (1 << (p + (1 << i)) <= x) {
            p += (1 << i);
        }
    }
    return p;
}

void build (int n) {
    for (int i = 1; 1 << i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            T[i][j] = min(T[i - 1][j], T[i - 1][j + (1 << (i - 1))]);
        }
    }
}
void find (int n) {
    int h;
    for (int k = 1, p = 1; k < 1 << 30; k <<= 1, p = 1) {
        S[1] = 0, T[0][1] = 1ll << 60;
        for (int i = 1; i <= n; i++) {
            if (X[i] >= k && X[i] < k << 1) {
                P[i] = ++p;
                S[p] = X[i] + S[p - 1];
                T[0][p] = X[i];
                p++;
            } else {
                P[i] = p;
            }
            S[p] = S[p - 1], T[0][p] = 1ll << 60;
        }

        build(p);
        
        for (auto [l, r, t] : Q) {
            l = P[l], r = P[r], h = highbit(r - l + 1);
            if (ans[t] >= min(T[h][l], T[h][r + 1 - (1 << h)])) {
                ans[t] += S[r] - S[l - 1];
            }
        }
    }
}

int32_t main () {
    int n, q, l, r;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> X[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        Q.push_back({l, r, i});
        ans[i] = 1;
    }
    
    find(n);
    
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}