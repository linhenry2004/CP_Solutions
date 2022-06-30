#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;

bool isValid (int x, int y) {
    return abs(x - y) <= k;
}

int main () {
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int count = 0;
    int i = 0, j = 0;
    while (i < a.size()) {
        while (j < b.size() && b[j] < a[i] - k) {
            j++;
        }
        if (isValid(a[i], b[j])) {
            count++;
            i++;
            j++;
        } else {
            i++;
        }
    }

    cout << count << endl;
    return 0;
}