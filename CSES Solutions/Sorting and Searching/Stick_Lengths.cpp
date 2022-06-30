#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll cost = 0;
    for (int i = 0; i < n; i++) {
        cost += abs(a[i] - a[n / 2]);
    }

    cout << cost << endl;
    return 0;
}