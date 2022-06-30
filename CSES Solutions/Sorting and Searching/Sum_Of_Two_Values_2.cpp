#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main () {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    while (r > l) {
        int sum = a[l].first + a[r].first;
        if (sum > x) {
            r--;
        } else if (sum < x) {
            l++;
        } else { //sum == x
            cout << a[l].second << " " << a[r].second;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}