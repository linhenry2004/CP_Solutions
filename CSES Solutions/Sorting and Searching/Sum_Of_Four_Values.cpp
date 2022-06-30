#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main () {
    int n;
    long long x;
    cin >> n >> x;
    vector <pair<long long, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            long long ans = x - a[i].first - a[j].first;
            int l = j + 1, r = n - 1;
            while (r > l) {
                if (a[l].first + a[r].first > ans) {
                    r--;
                } else if (a[l].first + a[r].first < ans) {
                    l++;
                } else { //sum == ans
                    cout << a[i].second << " " << a[j].second << " " << a[l].second << " " << a[r].second;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}