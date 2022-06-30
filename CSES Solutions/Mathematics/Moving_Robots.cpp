#include <bits/stdc++.h>
using namespace std;
#define matrix array<array<double, 8>, 8>

matrix dp, cnt, tmp, E;

void build () {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            E[i][j] = 1;
            if (i != 0) {
                cnt[i][j] += 1;
            }
            if (i != 7) {
                cnt[i][j] += 1;
            }
            if (j != 0) {
                cnt[i][j] += 1;
            }
            if (j != 7) {
                cnt[i][j] += 1;
            }
        }
    }
}

void reset () {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            dp[i][j] = 0;
        }
    }
}

void clear () {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tmp[i][j] = 0;
        }
    }
}

void move (int i, int j) {
    if (i != 0) {
        tmp[i - 1][j] += dp[i][j] / cnt[i][j];
    }
    if (i != 7) {
        tmp[i + 1][j] += dp[i][j] / cnt[i][j];
    }
    if (j != 0) {
        tmp[i][j - 1] += dp[i][j] / cnt[i][j];
    }
    if (j != 7) {
        tmp[i][j + 1] += dp[i][j] / cnt[i][j];
    }
}

void trans () {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            dp[i][j] = tmp[i][j];
        }
    }
}

int main () {
    int n;
    cin >> n;

    double ans = 0;
    build();

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            reset();
            dp[x][y] = 1;
            for (int k = 0; k < n; k++) {
                clear();
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        move(i, j);
                    }
                }
                trans();
            }
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    E[i][j] *= (1.0 - dp[i][j]);
                }
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ans += E[i][j];
        }
    }

    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}