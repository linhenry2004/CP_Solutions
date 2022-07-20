#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int j = n - 1;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                j = i;
                break;
            }
        }

        int ans = 0;
        for (int i = j; i <= n - 2; i++) {
            if (a[i] == 0) {
                ans++;
            } else {
                ans += a[i];
            }
        }
        cout <<ans << endl;
    }
    return 0;
}
