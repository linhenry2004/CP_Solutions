#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 1004;
int H[maxn];
char G[maxn][maxn];
int cnt[maxn][maxn];

void run (int n, int m) {
    int now;
    for (int i = 1; i <= n; i++) {
        stack<pair<int, int>> S;
        S.push({0, 0});
        for (int j = 1; j <= m; j++) {
            now = j;
            if (G[i][j] == '*') {
                H[j] = 0;
            } else {
                H[j]++;
            }
            while (!S.empty()) {
                auto [h, p] = S.top();
                if (H[j] < h) {
                    cnt[h][j - p]++;
                    S.pop();
                    now = p;
                    auto [h2, p2] = S.top();
                    cnt[max(h2, H[j])][j - p]--;
                } else {
                    break;
                }
            }
            S.push({H[j], now});
        }
    }
    for (int i = n; i; i--) {
        for (int j = m; j; j--) {
            cnt[i][j] += cnt[i][j + 1];
        }
    }
    for (int i = n; i; i--) {
        for (int j = m; j; j--) {
            cnt[i][j] += cnt[i + 1][j] + cnt[i][j + 1] - cnt[i + 1][j + 1];
        }
    }
}

int32_t main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> G[i][j];
        }
        G[i][m + 1] = '*';
    }
    run(n, m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << cnt[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}