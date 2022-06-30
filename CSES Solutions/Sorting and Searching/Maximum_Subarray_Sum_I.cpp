#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main () {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0;  i < n; i++) {
        cin >> a[i];
    }
    ll best = -1e18;
    ll past = 0;
    for (int i = 0; i < n; i++) {
        if (past + a[i] >= a[i]) {
            past += a[i];
        } else { // past + a[i] < a[i]
            past = a[i];
        }
        best = max(past, best);
    }
    cout << best << endl;
    return 0;
}