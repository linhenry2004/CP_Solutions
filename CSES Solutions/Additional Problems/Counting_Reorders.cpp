#include <bits/stdc++.h>
using namespace std;
 
const int N = 5007, MOD = 1000000007;
int choose[N][N], cur[N], nxt[N];
int add (int a, int b) { return a -= ((a += b) >= MOD) ? MOD : 0; }
int sub (int a, int b) { return a += ((a -= b) < 0) ? MOD : 0; }
int mul (int a, int b) { return int((int64_t) a * b % MOD); }

int main () {
    for (int i = 0; i < N; ++i) choose[i][0] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= i; ++j) {
            choose[i][j] = add(choose[i - 1][j - 1], choose[i - 1][j]);
        }
    }
    
    vector<int> cnt(26);
    string s; cin >> s;
    for (auto c : s) ++cnt[c - 'a'];
    
    cur[0] = 1;
    int n = 0;
    for (int m : cnt) if (m) {
        memset(nxt, 0, sizeof nxt);
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int x = cur[i];
                x = mul(x, choose[m - 1][j - 1]);
                x = mul(x, choose[i + j][j]);
                nxt[i + j] = add(nxt[i + j], x);
            }
        }
        n += m;
        memcpy(cur, nxt, sizeof nxt);
    }
    
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if ((n - i) & 1) ans = sub(ans, nxt[i]);
        else ans = add(ans, nxt[i]);
    }
    cout << ans << endl;
}