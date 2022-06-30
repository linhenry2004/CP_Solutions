#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int p;
            cin >> p;
            if (~i & 1) {
                ans ^= p;
            }
        }
        cout << (ans ? "first" : "second") << endl;
    }
    return 0;
}