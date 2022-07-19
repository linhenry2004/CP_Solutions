#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k * k < n) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        int l = 0;
        for (int i = k; i < n + k; i += k) {
            for (int j = min(i, n); j > l; j--) {
                cout << j << " ";
            }
            l = i;
        }
        cout << endl;
    }
    return 0;
}