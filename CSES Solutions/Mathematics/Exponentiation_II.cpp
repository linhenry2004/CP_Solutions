#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;

int power (int x, int k, int p) {
    int ans = 1;
    for (int i = 1; i <= k; i <<= 1) {
        if (i & k) {
            ans *= x;
            ans %= p;
        }
        x *= x;
        x %= p;
    }
    return ans;
}

int32_t main () {
    int n, a, b, c; 
    cin >> n;
    while (n--) {
        cin >> a >> b >> c; 
        int bc = power(b, c, mod - 1);
        cout << power(a, bc, mod) << endl;
    }
    return 0;
}