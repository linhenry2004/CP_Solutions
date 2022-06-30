#include <bits/stdc++.h>
using namespace std;
#define int long long int 

#define mid ((l + r) / 2)
#define lc (p << 1)
#define rc ((p << 1) | 1)

const int maxn = 1e5 + 1;
int SA[maxn], RNK[maxn], F[maxn], L[maxn];
int seg[4 * maxn], tag[4 * maxn];
vector<int> buk[maxn];

void pull (int p) {
    seg[p] = seg[lc] + seg[rc];
}

void push (int p, int l, int r) {
    seg[lc] += (mid - l + 1) * tag[p];
    seg[rc] += (r - mid) * tag[p];
    tag[lc] += tag[p];
    tag[rc] += tag[p];
    tag[p] = 0;
}

void update (int p, int ql, int qr, int v, int l, int r) {
    if (qr < l || ql > r) {
        return;
    }
    if (ql <= l && qr >= r) {
        seg[p] += (r - l + 1) * v;
        tag[p] += v;
        return;
    }

    push(p, l, r);

    update(lc, ql, qr, v, l, mid);
    update(rc, ql, qr, v, mid + 1, r);
    
    pull(p);
}

int query (int p, int ql, int qr, int l, int r) {
    if (ql > r || qr < l) {
        return 0;
    }
    if (ql <= l && qr >= r) {
        return seg[p];
    }

    push(p, l, r);
    return (query(lc, ql, qr, l, mid) + query(rc, ql, qr, mid + 1, r));
}

void sort (int A[maxn], int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        buk[A[SA[i]]].push_back(SA[i]);
    }
    for (int i = 0; i < max(n, 26ll); i++) {
        for (int x : buk[i]) {
            SA[cnt++] = x;
        }
        buk[i].clear();
    }
}

void suf (string &S) {
    int n = S.size(), ff = -1, ll = -1, cnt = -1;
    for (int i = 0; i < n; i++) {
        SA[i] = i;
        F[i] = S[i] - 'a';
    }
    sort(F, n);
    for (int i = 0; i < n; i++) {
        if (F[SA[i]] == ff && L[SA[i]] == ll) {
            RNK[SA[i]] = cnt;
        } else {
            RNK[SA[i]] = ++cnt;
        }
        ff = F[SA[i]], ll = L[SA[i]];
    }
    for (int j = 1; j < n; j <<= 1) {
        cnt = ff = ll = -1;
        for (int i = 0; i < n; i++) {
            F[i] = RNK[i];
            L[i] = (i + j < n) ? RNK[i + j] : 0;
        }
        sort(L, n);
        sort(F, n);
        for (int i = 0; i < n; i++) {
            if (F[SA[i]] == ff && L[SA[i]] == ll) {
                RNK[SA[i]] = cnt;
            } else {
                RNK[SA[i]] = ++cnt; 
            }
            ff = F[SA[i]], ll = L[SA[i]];
        }
    }
    for (int i = 0; i < n; i++) {
        update(1, i, i, n - SA[i], 0, n);
    }
}

int bis (string &S, int t, int l, int r, char c) {
    int p = l - 1;
    for (int i = 1 << 16; i > 0; i >>= 1) {
        if (p + i <= r && S[SA[p + i] + t] <= c) {
            p += i;
        }
    }
    return p;
}

char cha (string &S, int k, int t, int l, int r) {
    int p, n = S.size();
    char cl = 'a', cr = 'z', cm;
    while (cl != cr) {
        cm = (cl + cr) >> 1;
        p = bis(S, t, l, r, cm);
        if (query(1, l, p, 0, n) < k) {
            cl = cm + 1;
        } else {
            cr = cm;
        }
    }
    return cl;
}

string see (string &S, int k) {
    int n = S.size(), l = 0, r = n - 1, t = 0, tmp;
    char p;
    string s;
    while (k > 0) {
        p = cha(S, k, t, l, r);
        tmp = l;
        l = bis(S, t, l, r, p - 1) + 1;
        k -= query(1, tmp, l - 1, 0, n);
        r = bis(S, t, l, r, p);
        update(1, l, r, -1, 0, n);
        k -= r - l + 1;
        s += p;
        t++;
    }
    return s;
}

int32_t main () {
    int k;
    string S;
    cin >> S >> k;
    suf(S);
    cout << see(S, k) << endl;
    return 0;
}