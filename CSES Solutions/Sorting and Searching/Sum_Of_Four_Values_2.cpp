#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct pairSum {
    int sum;
    int first;
    int second;
    
    bool operator < (const pairSum& str) const
    {
        return (sum < str.sum);
    }
};
 
bool noCommon(pairSum a, pairSum b) {
    return (a.first != b.first && a.first != b.second && a.second != b.first && a.second != b.second);
} 
 
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    int size = (n * (n - 1)) / 2;
    vector<pairSum> b(size);
    int k = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            b[k].sum = a[i].first + a[j].first;
            b[k].first = a[i].second;
            b[k].second = a[j].second;
            k++;
        }
    }
    sort(b.begin(), b.end());
    int l = 0, r = size - 1;
    while (r > l) {
        int temp = b[l].sum + b[r].sum;
        bool duplicate = noCommon(b[l], b[r]);
        if (temp == x && duplicate) {
            cout << b[l].first << " " << b[l].second << " " << b[r].first << " " << b[r].second << endl;
            return 0;
        } else if (temp == x && !duplicate) {
            l++;
        } else if (temp < x) {
            l++;
        } else if (temp > x) {
            r--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}