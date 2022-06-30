#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9

int main () {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> b(x + 1, INF);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    b[0] = 0;
    for (int value = 1; value <= x; value++) {
        for (int j = 0; j < n; j++) {
            if (value - a[j] >= 0) {
                b[value] = min(b[value], b[value - a[j]] + 1);
            }
        }
    }
    cout << (b[x] == INF ? -1 : b[x]) << endl;
    return 0;
}