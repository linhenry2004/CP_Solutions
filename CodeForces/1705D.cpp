#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> cnt1(n + 1), cnt2(n + 1);
        string str1, str2;
        cin >> str1 >> str2;

        cnt1[0] = cnt2[0] = 1;
        for (int i = 1; i < n; i++) {
            if (str1[i] == str1[i - 1]) {
                cnt1[i] = cnt1[i - 1];
            } else {
                cnt1[i] = cnt1[i - 1] + 1;
            }
        }

        for (int i = 1; i < n; i++) {
            if (str2[i] == str2[i - 1]) {
                cnt2[i] = cnt2[i - 1];
            } else {
                cnt2[i] = cnt2[i - 1] + 1;
            }
        }

        if (cnt1[n - 1] != cnt2[n - 1] || str1[0] != str2[0]) {
            cout << -1 << endl;
            continue;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs(cnt2[i] - cnt1[i]);
        }
        cout << ans << endl;
    }
    return 0;
}