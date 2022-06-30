#include <bits/stdc++.h>
using namespace std;

#define mid ((l + r) / 2)
#define lc (p << 1)
#define rc ((p << 1) | 1)

const int INF = 1e9;
const int maxn = 1e5 + 1;
int seg[4 * maxn];
int SA[maxn], RNK[maxn], F[maxn], L[maxn];
vector<int> buk[maxn];

void update (int p, int c, int x, int l, int r) {
    if (c < l || c > r) {
        return;
    }
    if (l == r) {
        seg[p] = x;
        return;
    }

    update(lc, c, x, l, mid);
    update(rc, c, x, mid + 1, r);
    seg[p] = min(seg[lc], seg[rc]);
}

int query (int p, int ql, int qr, int l, int r) {
    if (ql > r || qr < l) {
        return INF;
    }
    if (ql <= l && qr >= r) {
        return seg[p];
    }
    return min(query(lc, ql, qr, l, mid), query(rc, ql, qr, mid + 1, r));
}

void sort (int A[maxn], int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        buk[A[SA[i]]].push_back(SA[i]);
    }
    for (int i = 0; i < max(n, 26); i++) {
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
        update(1, i, SA[i], 0, S.size() - 1);
    }
}

bool cmp (string &T, string &S, int k, bool t) {
    for (int i = 0; i < T.size() && i + k < S.size(); i++) {
        if (T[i] < S[k + i]) {
            return 1;
        } else if (T[i] > S[k + i]) {
            return 0;
        }
    }
    if (T.size() > S.size() - k) {
        return 0;
    }
    return t ^ 1;
}

int BS (string &S, string &T, bool t) {
    int l = 0, r = S.size() - 1;
    while (l != r) {
        if (cmp(T, S, SA[mid], t)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int pos (string &S, string &T) {
    if (BS(S, T, 1) == BS(S, T, 0)) {
        return -1;
    } 
    return query(1, BS(S, T, 0), BS(S, T, 1) - 1, 0, S.size() - 1) + 1;
}

int main () {
    int k;
    string S, T;
    cin >> S >> k;
    S += '~';
    for (int &s : seg) {
        s = INF;
    }
    suf(S);
    while (k--) {
        cin >> T;
        cout << pos(S, T) << endl;
    }
    return 0;
}