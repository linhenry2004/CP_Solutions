#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int r = n - 1, l = 0;
    int count = 0;
    while (r > l) {
        int temp = a[r] + a[l];
        if (temp > x) {
            count++;
            r--;
        } else { // temp <= x
            count++;
            r--;
            l++;
        }
    }
    if (r == l) {
        count++;
    }

    cout << count << endl;
    return 0;
}