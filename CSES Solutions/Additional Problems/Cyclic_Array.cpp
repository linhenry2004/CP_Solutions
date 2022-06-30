#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 2e5 + 1;
int n, k;
int X[maxn];

int see (int p) {
    int sum = 0, cnt = 0, s, t;
    for (s = 1; s <= n; s++) {
        if (sum + X[s] > p) {
            break;
        }
        sum += X[s];
    }
    for (t = n; t >= s; t--) {
        if (sum + X[t] > k) {
            break;
        }
        sum += X[t];
    }

    if (sum) {
        cnt++;
    }
    sum = 0;

    for (int i = s; i <= t; i++) {
        if (sum + X[i] > k) {
            sum = 0;
            cnt++;
        }
        sum += X[i];
    }
    if (sum) {
        cnt++;
    }
    return cnt;
}

int TIS () {
    int l = 0, r = k, lm, rm, ans = 1e9;
    while (r - l > 2) {
        lm = (2 * l + r) / 3ll;
        rm = (l + 2 * r) / 3ll;
        if (see(lm) < see(rm)) {
            r = rm;
        } else {
            l = lm;
        }
    }
    for (int i = l; i <= r; i++) {
        ans = min(ans, see(i));
    }
    return ans;
}

int32_t main () {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> X[i];
    }
    cout << TIS() << endl;
    return 0;
}