#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct range {
    int l;
    int r;
    int index;

    bool operator < (const range &other) const {
        if (l == other.l) {
            return r > other.r;
        }

        return l < other.l;
    }
};

int main () {
    int n;
    cin >> n;

    vector<range> ranges(n);
    ordered_set<pair<int, int>> rightboundaries;
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].index = i;
    }
    sort(ranges.begin(), ranges.end());

    vector<int> contained(n);
    for (int i = 0; i < n; i++) {
        rightboundaries.insert({ranges[i].r, i * (-1)});
        contained[ranges[i].index] = rightboundaries.size() - rightboundaries.order_of_key({ranges[i].r, i * (-1)}) - 1;
    }

    rightboundaries.clear();

    vector<int> contains(n);
    for (int i = n - 1; i >= 0; i--) {
        rightboundaries.insert({ranges[i].r, i * (-1)});
        contains[ranges[i].index] = rightboundaries.order_of_key({ranges[i].r, i * (-1)});
    }

    for (auto c : contains) {
        cout << c << " ";
    }
    cout << endl;

    for (auto c : contained) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}