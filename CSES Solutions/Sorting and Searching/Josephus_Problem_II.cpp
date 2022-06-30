#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main () {
    int n, k;
    cin >> n >> k;
    ordered_set children;
    for (int i = 1; i <= n; i++) {
        children.insert(i);
    }

    int index = 0;
    while (children.size() > 0) {
        index %= children.size();
        int pos = (index + k) % children.size();
        index = pos;
        auto t = children.find_by_order(pos);
        cout << *t << " ";
        children.erase(t);
    }
    cout << endl;
    return 0;
}