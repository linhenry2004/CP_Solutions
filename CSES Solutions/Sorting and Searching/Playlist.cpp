#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    set<int> b; 
    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < n) {
        while (j < n && !b.count(a[j])) {
            b.insert(a[j]);
            ans = max(ans, j - i + 1);
            j++;
        }

        while (j < n && b.count(a[j])) {
            b.erase(a[i]);
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}