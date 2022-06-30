#include <iostream>
#include <vector>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;

int main () {
    int n, m;
    cin >> n >> m;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    vector<vector<ll>> arrays(n, vector<ll> (m + 1, 0));
    if (values[0] != 0) {
        arrays[0][values[0]] = 1;
    } else {
        for (int i = 1; i <= m; i++) {
            arrays[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        if (values[i] == 0) {
            for (int j = 1; j <= m; j++) {
                if (j - 1 >= 1) {
                    arrays[i][j] = (arrays[i][j] + arrays[i - 1][j - 1]) % mod;
                }

                arrays[i][j] = (arrays[i][j] +  arrays[i - 1][j]) % mod;

                if (j + 1 <= m) {
                    arrays[i][j] = (arrays[i][j] + arrays[i - 1][j + 1]) % mod;
                }
            }
        } else {
            if (values[i] - 1 >= 1) {
                arrays[i][values[i]] = (arrays[i][values[i]] + arrays[i - 1][values[i] - 1]) % mod;
            }

            arrays[i][values[i]] = (arrays[i][values[i]] +  arrays[i - 1][values[i]]) % mod;

            if (values[i] + 1 <= m) {
                arrays[i][values[i]] = (arrays[i][values[i]] + arrays[i - 1][values[i] + 1]) % mod;
            }
        }
    }

    ll sum = 0;
    for (int i = 1; i <= m; i++) {
        sum = (sum + arrays[n - 1][i]) % mod;
    }
    cout << sum << endl;
    return 0;
}