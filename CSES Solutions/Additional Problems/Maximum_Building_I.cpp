#include <bits/stdc++.h>
using namespace std;

const int maxn = 1004;
int H[maxn];
char G[maxn][maxn];
stack<pair<int, int>> S;

int run (int n, int m) {
    int ans = 0, now;
    for (int j = 1; j <= n; j++) {
        S.push({0, 0});
        for (int i = 1; i <= m; i++) {
            now = i;
            if (G[j][i] == '*') {
                H[i] = 0;
            } else {
                H[i]++;
            }
            while (!S.empty() && H[i] <= S.top().first) {
                auto [h, p] = S.top();
                S.pop();
                ans = max(ans, (i - p) * h);
                now = p;
            }
            S.push({H[i], now});
        }

        while (!S.empty()) {
            auto [h, p] = S.top();
            S.pop();
            ans = max(ans, (m - p + 1) * h);
        }
    }
    return ans;
}

int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> G[i][j];
        }
    }

    cout << run(n, m) << endl;
    return 0;
}