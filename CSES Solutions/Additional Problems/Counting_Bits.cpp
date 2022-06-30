#include <bits/stdc++.h>
using namespace std;
#define int long long int

int cal (int n) {
    int ans = 0;
    for (int i = 1ll << 50; i > 0; i >>= 1) {
        if (n <= i) {
            continue;
        }
        ans += (n / (i << 1)) * i;
        ans += (n % (i << 1)) - min(i, n % (i << 1));
    }
    return ans;
}

int32_t main () {
    int n;
    cin >> n;
    cout << cal(n + 1) << endl;
    return 0;
}