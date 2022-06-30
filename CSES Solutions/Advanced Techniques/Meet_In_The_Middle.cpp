#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 1 << 20;
vector<int> T(40);
vector<int> F(maxn);
vector<int> S(maxn);

void ju (int s, int t, vector<int> &A) {
    for (int i = 0; i < 1 << (t - s); i++) {
        for (int j = 0; j < (t - s); j++) {
            if (i & (1 << j)) {
                A[i] = T[s + j] + A[i ^ (1 << j)];
                break;
            }
        }
    }
}

int32_t main () {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }

    ju(0, n / 2, F);
    ju(n / 2, n, S);
    int s = 1 << (n - n / 2);
    sort(S.begin(), S.begin() + s);

    int cnt = 0;
    for (int f : F) {
        if (f) {
            cnt += upper_bound(S.begin(), S.begin() + s, x - f) - lower_bound(S.begin(), S.begin() + s, x - f);
        }
    }

    cnt += upper_bound(S.begin(), S.begin() + s, x) - lower_bound(S.begin(), S.begin() + s, x);
    cout << cnt << endl;
    return 0;
}