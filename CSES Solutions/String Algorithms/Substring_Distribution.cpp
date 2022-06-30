#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int maxn = 1e5 + 1;
int SA[maxn], RNK[maxn], F[maxn], L[maxn], LCP[maxn];
vector<int> buk[maxn];

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
        SA[i] = n - i - 1;
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
}

void lcp (string &S) {
    int n = S.size(), cp = 0, k;
    for (int i = 0; i < n; i++) {
        RNK[SA[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        if (!RNK[i]) {
            LCP[0]++;
            LCP[n - i]--;
            continue;
        }
        k = SA[RNK[i] - 1];
        if (cp) {
            cp--;
        }
        while (S[i + cp] == S[k + cp]) {
            cp++;
        }
        LCP[cp]++;
        LCP[n - i]--;
    }
}

int32_t main () {
    int ans = 0;
    string S;
    cin >> S;
    suf(S);
    lcp(S);
    for (int i = 0; i < S.size(); i++) {
        ans += LCP[i];
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}