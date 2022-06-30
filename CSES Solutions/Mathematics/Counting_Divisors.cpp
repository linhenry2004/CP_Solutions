#include <bits/stdc++.h>
using namespace std;

int div (int x) {
    int cnt = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            cnt += 2;
        }
        if (i * i == x) {
            cnt--;
        }
    }
    return cnt;
}

int main () {
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        cout << div(x) << endl;
    }
    return 0;
}