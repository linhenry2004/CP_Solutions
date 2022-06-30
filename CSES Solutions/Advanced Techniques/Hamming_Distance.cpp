#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e4 + 1;
int S[maxn];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, ans = 30;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            char b;
            cin >> b;
            S[i] <<= 1;
            S[i] |= b ^ '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n ; j++) {
            ans = min(ans, (int)__builtin_popcount(S[i] ^ S[j]));
        }
    }

    cout << ans << endl;
    return 0;
}