#include <iostream>
#include <vector>
using namespace std;

#define ll long long

const int mod = 1e9 +7;

int main () {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<ll> combo(x + 1, 0);
    combo[0] = 1;
    for (int val = 1; val <= x; val++) {
        for (int j = 0; j < n; j++) {
            if (val - coins[j] >= 0) {
                combo[val] = (combo[val] + combo[val - coins[j]]) % mod;
            }
        }
    }
    cout << combo[x] << endl;
    return 0;
}