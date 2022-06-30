#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define int long long

int32_t main () {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    map<int, int> mp;
    int ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && ((int)mp.size() < k || mp.count(v[j]) > 0)) {
            mp[v[j]]++;
            j++;
        }

        ans += j - i;
        mp[v[i]]--;
        if (mp[v[i]] == 0) {
            mp.erase(v[i]);
        }
    }
    cout << ans << endl;
    return 0;
}