#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 3000;
array<bitset<maxn>, maxn> G;

int32_t main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, ans = 0, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> G[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tmp = (G[i] & G[j]).count();
            ans += tmp * (tmp - 1);
        }
    }

    cout << ans / 2 << endl;
    return 0;
}