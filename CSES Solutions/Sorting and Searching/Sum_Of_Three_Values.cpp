#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n, x;
    cin >> n >> x;
    vector <pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int ans = x - a[i].first;
        int l = i + 1, r = n - 1;
        while (r > l) {
            if (a[l].first + a[r].first > ans) {
                r--;
            } else if (a[l].first + a[r].first < ans) {
                l++;
            } else { //sum == ans
                cout << a[i].second << " " << a[l].second << " " << a[r].second;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}