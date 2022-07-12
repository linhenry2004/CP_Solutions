#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 2e5 + 1;
int A[maxn], B[maxn], cur[maxn];

int run (int n, int p) {
    int cnt = llabs(p);
    for (int i = 1; i <= n; i++) {
        cur[i] = A[i];
    }

    cur[n] -= p;
    cur[1] += p;

    for (int i = 1; i < n; i++) {
        cnt += llabs(cur[i] - B[i]);
        cur[i + 1] += cur[i] - B[i];
        cur[i] = B[i];
    }
    return cnt;
}

int TIS (int n) {
    int l = -1e12, r = 1e12, lmid, rmid;

    while (r - l > 2) {
        lmid = (2 * l + r) / 3;
        rmid = (2 * r + l) / 3;
        if (run(n, lmid) < run(n, rmid)) {
            r = rmid;
        } else {
            l = lmid;
        }
    }
    return min({run(n, l), run(n, l + 1), run(n, r)});
}

int32_t main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    cout << TIS(n) << endl;
    return 0;
}