#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define ll long long 

const ll INF = 1e18;
const ll NINF = INF * -1;

int main () {
    int n, a, b; 
    cin >> n >> a >> b; 
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        v[i] += v[i - 1];
    }

    set<pair<ll, int>> bound;
    for (int i = a; i <= b; i++) {
        bound.insert({v[i], i});
    }
    
    ll ans = NINF;
    for (int i = 1; i <= n - a + 1; i++) {
        ans = max(ans, bound.rbegin()->first - v[i - 1]);
        bound.erase({v[i + a - 1], i + a - 1});
        if (i + b <= n) {
            bound.insert({v[i + b], i + b});
        }
    }

    cout << ans << endl;
    return 0;
}