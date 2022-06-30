#include <iostream>
using namespace std;

int main () {
    int n, ans;
    cin >> n >> ans;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (arr[mid] < ans) l = mid;
        else r = mid;
    }
    cout << r + 1 << endl;
    return 0;
}