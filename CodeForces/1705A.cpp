#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        vector<int> v;
        cin >> n >> x;
        int q = 2 * n;
        int a[q];
        for (int i = 0; i < q; i++) {
            cin >> a[i];
        }
        sort(a, a + q);

        int p = 0;
        for (int i = 0; i < n; i++) {
            if ((a[i] + x) <= a[n + i]) {
                p++;
            } else {
                cout << "NO" << endl;
                break;
            }
        }
        if (p == n) {
            cout << "YES" << endl;
        }
    }
    return 0;
}