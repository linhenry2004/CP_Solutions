#include <bits/stdc++.h>
using namespace std;
#define int long long int

int a[20];

int mul (int n, int k) {
    int ans = 0, tmp, cnt; 
    for (int i = 1; i < 1 << k; i++) {
        tmp = n, cnt = 0;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                tmp /= a[j];
                cnt++;
            }
        }
        if (cnt & 1) {
            ans += tmp;
        } else {
            ans -= tmp;
        }
    }
    return ans;
}

int32_t main () {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    cout << mul(n, k) << endl;
    return 0;
}