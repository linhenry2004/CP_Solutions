#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string a[n], b[n - 1];
        int cnt[m] = {0};
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt[j] += a[i][j];
            }
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j =0; j < m; j++) {
                cnt[j] -= b[i][j];
            }
        }
        
        for (int i : cnt) {
            cout << char(i);
        }
        cout << endl;
    }
}