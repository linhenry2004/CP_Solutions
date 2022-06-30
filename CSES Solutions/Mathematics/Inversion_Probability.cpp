#include <bits/stdc++.h>
using namespace std;

double R[101];

int main () {
    int n;
    cin >> n;
    double ans = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (double k = 2; k <= R[i]; k += 1) {
                ans += min(k - 1, R[j]) / R[j] / R[i];
            }
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}