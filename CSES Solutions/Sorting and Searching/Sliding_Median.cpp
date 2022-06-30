#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long

int32_t main () {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    ordered_multiset<int> st;
    queue<int> q;

    for (int i = 0; i < k - 1; i++) {
        st.insert(v[i]);
        q.push(v[i]);
    }

    int end = k - 1;
    while (end < n) {
        st.insert(v[end]);
        q.push(v[end]);

        if(k % 2 == 1) {
            cout << *st.find_by_order(k / 2) << " ";
        } else {
            cout << *st.find_by_order(k / 2 - 1) << " ";
        }

        int p = q.front();
        st.erase(st.find_by_order(st.order_of_key(p)));
        q.pop();

        end++;
    }
    return 0;
}