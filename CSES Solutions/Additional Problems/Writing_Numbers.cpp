#include <bits/stdc++.h>
using namespace std;
#define int long long int

int see (int n) {
    int ans = 0, cnt;
    for (int i = 1; i < 10; i++) {
        cnt = 0;
        for (int t = 1; t <= n; t *= 10) {
            cnt += (n / (10 * t)) * t;
            cnt += min(t, max(0ll, n % (10 * t) - i * t + 1));
        }
        ans = max(ans, cnt);
    }
    return ans;
}

int BIS (int k) {
    int l = 0, r = 1e18, mid;
    while (l != r) {
        mid = ((l + r) >> 1) + 1;
        if (see(mid) <= k) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int32_t main () {
    int n;
    cin >> n;
    cout << BIS(n) << endl;
    return 0;
}