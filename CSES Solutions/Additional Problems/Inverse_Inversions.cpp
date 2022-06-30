#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 1e6 + 1;
int P[maxn];

void run (int n, int k) {
    int l = 1, r = n;
    for (int i = 1; i <= n; i++) {
        if (k >= n - i) {
            P[i] = r--;
            k -= n - i;
        } else {
            P[i] = l++;
        }
    }
}

int32_t main () {
    int n, k;
    cin >> n >> k;
    run(n, k);
    for (int i = 1; i <= n; i++) {
        cout << P[i] << " ";
    }
    cout << endl;
    return 0;
}