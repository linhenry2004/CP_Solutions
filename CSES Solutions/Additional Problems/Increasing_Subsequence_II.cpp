#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 2e5 + 1;
const int mod = 1e9 + 7;
int X[maxn], BIT[maxn];

void update(int p, int x) {
    for (; p < maxn; p += p & -p) {
        BIT[p] += x;
    }
}

int query (int p) {
    int sum = 0;
    for (; p; p -= p & -p) {
        sum += BIT[p];
        sum %= mod;
    }
    return sum;
}

void umbrella (vector<pair<int, int>> &S) {
    int lst = 0, cnt = 1;
    sort(S.begin(), S.end());
    for (auto [x, p] : S) {
        if (x == lst) {
            X[p] = cnt;
        } else {
            X[p] = ++cnt;
        }
        lst = x;
    }
}

int DP (int n) {
    int ans = 0, cnt;
    update(1, 1);
    for (int i = 1; i <= n; i++) {
        cnt = query(X[i] - 1);
        update(X[i], cnt);
        ans = (ans + cnt) % mod;
    }
    return ans;
}

int32_t main () {
    int n;
    cin >> n;
    vector<pair<int, int>> S;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        S.push_back({x, i});
    }

    umbrella(S);
    cout << DP(n) << endl;
    return 0;
}