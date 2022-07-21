#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, c, q;
        cin >> n >> c >> q;
        string str;
        cin >> str;

        vector<pair<int, int>> positions;
        positions.push_back({1, 1});
        positions.push_back({n, n});

        while (c--) {
            int l, r;
            cin >> l >> r;
            int prev = positions.back().second;
            positions.push_back({l, prev + 1});
            positions.push_back({r, prev + 1 + r - l});
        }

        while (q--) {
            int p;
            cin >> p;
            while (p > n) {
                int tmp = 0;
                for (int i = 0; i < positions.size(); i++) {
                    if (positions[i].second <= p) {
                        tmp = i;
                    } else {
                        break;
                    }
                }
                p = positions[tmp].first + p - positions[tmp].second;
            }
            cout << str[p - 1] << endl;
        }
    }
    return 0;
}