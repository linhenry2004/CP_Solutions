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
    for (int i = 0; i < k; i++) {
        st.insert(v[i]);
    }

    int P = *st.find_by_order((k + 1) / 2 - 1);
	int d = 0;
	for(int i = 0; i < k; i++) {
        d += abs(v[i] - P);
    }
	cout << d << " ";
	for(int i = 0; i < n - k; i++) {
		st.erase(st.find_by_order(st.order_of_key(v[i])));
		st.insert(v[i + k]);
		int p = *st.find_by_order((k + 1) / 2 - 1);
		d += abs(p - v[i + k]) - abs(P - v[i]);
		if(k % 2 == 0) {
            d -= p - P;
        }
		P = p;
		cout << d << " ";
    }
    cout << endl;
    return 0;
}