#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 2e5 + 1;
int n, q;
int p[maxn];
ordered_set<pair<int, int>> s;

int query (int x) {
    return s.order_of_key({x, 0});
}

int main () {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        s.insert({p[i], i});
    }

    for (int i = 0; i < q; i++) {
        char qt;
        int k, x;
        cin >> qt >> k >> x;
        if (qt == '!') {
            k--;
            s.erase({p[k], k});
            p[k] = x;
            s.insert({p[k], k});
        } else if (qt == '?') {
            cout << query(x + 1) - query(k) << endl;
        }
    }
    return 0;
}