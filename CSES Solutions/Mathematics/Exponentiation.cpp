#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;

int power (int x, int k) {
    int ans = 1;
    for (int i = 1; i <= k; i <<= 1) {
        if (k & i) {
            ans *= x;
            ans %= mod;
        } 
        x *= x;
        x %= mod;
    }
    return ans;
}

int32_t main () {
    int n, a, b; 
    cin >> n;
    while (n--) {
        cin >> a >> b; 
        cout << power(a, b) << endl;
    }
    return 0;
}