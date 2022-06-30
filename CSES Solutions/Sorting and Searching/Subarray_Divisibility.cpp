#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main () {
    int n;
    cin >> n;
    vector<ll> v(n), mod(n, 0);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        mod[((sum % n) + n) % n]++;
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (mod[i] > 1) {
            res += (mod[i] * (mod[i] - 1) / 2);
        }
    }

    res += mod[0];
    cout << res << endl;
    return 0;
}