#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
int n, q;
int a[maxn + 1][maxn + 1];
string s[maxn];

int main () {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '*') {
                a[i + 1][j + 1]++;
            }
        }

        for (int j = 0; j < n; j++) {
            a[i + 1][j + 1] += a[i + 1][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] += a[i - 1][j];
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--;
        x1--;
        cout << a[y2][x2] - a[y1][x2] - a[y2][x1] + a[y1][x1] << endl;
    }
    return 0;
}