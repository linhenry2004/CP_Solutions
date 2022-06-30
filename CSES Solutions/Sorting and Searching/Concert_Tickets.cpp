#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert({a[i], i});
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++) {
        auto match = s.lower_bound({b[i] + 1, 0});
        if (match == s.begin()) {
            cout << -1 << endl;
        } else {
            match--;
            cout << (*match).first << endl;
            s.erase(match);
        }
    }
    return 0;
}