#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 2e5 + 1;
int K[maxn];
stack<pair<int, int>> F;

int run (int n) {
    int ans = 0, p;
    for (int i = 1; i <= n; i++) {
        p = i;
        while (!F.empty()) {
            auto [l, h] = F.top();
            if (K[i] < h) {
                ans = max(ans, h * (i - l));
                F.pop();
                p = l;
            } else {
                break;
            }
        }
        F.push({p, K[i]});
    }
    while (!F.empty()) {
        auto [l, h] = F.top();
        F.pop();
        ans = max(ans, h * (n - l + 1));
    }
    return ans;
}

int32_t main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> K[i];
    }
    cout << run(n) << endl;
    return 0;
}