#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main () {
    int n;
    cin >> n;
    ordered_set pos;
    vector<int> content(n);
    for (int i = 0; i < n; i++) {
        cin >> content[i];
        pos.insert(i);
    }

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        cout << content[*pos.find_by_order(k - 1)] << " ";
        pos.erase(*pos.find_by_order(k - 1));
    }
    cout << endl;
    return 0;
}