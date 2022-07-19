#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define int long long int
 
int32_t main () {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    int m = 0;
    int count = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        m += a[i];
        if (m == x) {
            count++;
        }
 
        if (mp.count(m - x)) {
            count += mp[m - x];
        }
        mp[m]++;
    }
    cout << count << endl;
    return 0;
}