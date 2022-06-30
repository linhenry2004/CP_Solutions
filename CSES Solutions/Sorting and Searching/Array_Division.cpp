#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

const ll mx = 2e5 + 5;
ll n, k;
ll hi = 0,low = 9e18;
vector<ll> v(mx);

bool check (ll x) {
	ll temp = 0, cnt = 1;
	for(ll i = 0; i < n; i++) {
		if(v[i] > x) {
            return false;
        }

		if(v[i] + temp <= x) {
            temp+=v[i];
        } else {
			temp = v[i];
            cnt++;
		}
	}
	return cnt <= k;
}

int main () {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        hi += v[i];
        if (v[i] < low) {
            low = v[i];
        }
    }

    ll ans = -1;
    while (low <= hi) {
        ll mid = (low + hi) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}