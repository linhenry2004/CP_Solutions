#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 2e5 + 1;
int BIT[maxn];

void update(int p, int x) {
    for (; p < maxn; p += p & -p) {
        BIT[p] += x;
    }
}

int query (int p) {
    int sum = 0;
    for (; p; p -= p & -p) {
        sum += BIT[p];
    }
    return sum;
}

int32_t main () {
    int n;
    cin >> n;
    vector<pair<int, int>> S;
    
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        S.push_back({x, i});
        update(i, 1);
    }
    sort(S.begin(), S.end());

    int ans = 0;
    for (auto [v, p] : S) {
        ans += min(query(p - 1), query(2e5) - query(p));
        update(p, -1);
    }
    cout << ans << endl;
    return 0;
}