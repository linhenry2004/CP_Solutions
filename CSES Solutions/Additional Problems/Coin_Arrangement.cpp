#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 1e5 + 1;
int C[maxn][3];

int RUN (int n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (C[i][1] * C[i][2] < 0) {
            if (abs(C[i][1]) > abs(C[i][2])) {
                cnt += abs(C[i][2]);
                C[i][1] += C[i][2];
                C[i][2] = 0;
            } else {
                cnt += abs(C[i][1]);
                C[i][2] += C[i][1];
                C[i][1] = 0;
            }
        }
        cnt += abs(C[i][1] + C[i][2]);
        C[i + 1][1] += C[i][1];
        C[i + 1][2] += C[i][2];
    }
    return cnt;
}

int32_t main () {
    int n;
    cin >> n;
    for (int i : {1, 2}) {
        for (int j = 1; j <= n; j++) {
            cin >> C[j][i];
            C[j][i] -= 1;
        }
    }
    cout << RUN(n) << endl;
    return 0;
}