#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int maxn = 1e6 + 1;
int lpf[maxn], mobius[maxn];

void least_prime_factor () {
    for (int i = 2; i < maxn; i++) {
        if (!lpf[i]) {
            for (int j = i; j < maxn; j += i) {
                if (!lpf[j]) {
                    lpf[j] = i;
                }
            }
        }
    }
}
 
void Mobius () {
    for (int i = 1; i < maxn; i++) {
        if (i == 1) {
            mobius[i] = 1;
        } else {
            if (lpf[i / lpf[i]] == lpf[i]) {
                mobius[i] = 0;
            } else {
                mobius[i] = -1 * mobius[i / lpf[i]];
            }
        }
    }
}

int32_t main () {
    int n;
    cin >> n;
    int x[n], cnt[maxn] = {};
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cnt[x[i]]++;
    }

    least_prime_factor();
    Mobius();

    int ans = 0;
    for(int i = 1; i < maxn; i++) {
        if(mobius[i]==0) {
            continue;
        }
        int d = 0;
        for(int j = i; j < maxn; j += i) {
            d += cnt[j];
        }
        ans += (d * (d - 1)) / 2 * mobius[i];
    }
    cout << ans << endl;
    return 0;
}