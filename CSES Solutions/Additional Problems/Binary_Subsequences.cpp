#include <bits/stdc++.h>
using namespace std;

int maxn = 1e6 + 1;
int n;
string ans, s;

int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        int dp0 = i, dp1 = n - i;
        s.clear();
        while (dp0 != dp1) {
            if (dp0 > dp1) {
                s += '0';
                dp0 -= dp1 + 1;
            } else {
                s += '1';
                dp1 -= dp0 + 1;
            }
        }
        if (dp0 == 0) {
            if (s.size() < maxn) {
                maxn = s.size();
                ans = s;
            }
        }
    }
    reverse (ans.begin(), ans.end());
    cout << ans << endl;
}