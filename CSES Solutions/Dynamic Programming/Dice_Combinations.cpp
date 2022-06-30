#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main () {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    a[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                a[i] = (a[i] + a[i - j]) % mod;
            }
        }
    }
    cout << a[n] << endl;
    return 0;
}