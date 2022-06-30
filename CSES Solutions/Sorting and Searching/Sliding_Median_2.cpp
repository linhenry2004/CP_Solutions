#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define int long long

int32_t main () {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (k == 1) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return 0;
    }

    if (k == 2) {
        for (int i = 1; i < n; i++) {
            cout << min(a[i], a[i - 1]) << " ";
        }
        cout << endl;
        return 0;
    }

    set<pair<int, int>> left;
    set<pair<int, int>> right;
    vector<pair<int, int>> st;
    for (int i = 0; i < k; i++) {
        st.push_back({a[i], i});
    }
    sort(st.begin(), st.end());

    for (int i = 0; i < (k / 2) + (k % 2); i++) {
        left.insert(st[i]);
    }
    for (int i = (k / 2) + (k % 2); i < k; i++) {
        right.insert(st[i]);
    }

    auto t = left.rbegin();
    cout << t->first << " ";
    for (int j = 1; j < n - k + 1; j++) {
        if (left.count({a[j - 1], j - 1})) {
            left.erase({a[j - 1], j - 1});
        } else {
            right.erase({a[j - 1], j - 1});
        }

        if (*(left.rbegin()) < make_pair(a[k - 1 + j], k - 1 + j)) {
            right.insert({a[k - 1 + j], k - 1 + j});
        } else {
            left.insert({a[k - 1 + j], k - 1 + j});
        }

        while (left.size() < (k / 2) + (k % 2)) {
            pair<int, int> z = (*right.begin());
            left.insert(z);
            right.erase(z);
        }

        while (left.size() > (k / 2) + (k % 2)) {
            pair<int, int> z = (*left.rbegin());
            left.erase(z);
            right.insert(z);
        }

        cout << left.rbegin()->first << " ";
    }
    cout << endl;
    return 0;
}