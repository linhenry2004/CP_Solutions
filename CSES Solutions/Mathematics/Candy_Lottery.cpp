#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    double k, ans = 0, u, d;
    cin >> n >> k;
    for (double i = 1; i <= k; i += 1) {
        u = d = 1;
        for (int j = 0; j < n; j++) {
            u *= i / k;
            d *= (i - 1) / k;
        }
        ans += i * (u - d);
    }
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}