#include <iostream>
using namespace std;

void prefix_sum (long long arr[], int n, long long result[]) {
    result[0] = arr[0];
    for (int i = 1; i < n; i++) {
        result[i] = result[i - 1] ^ arr[i];
    }
}

int main () {
    int n, q; 
    cin >> n >> q;
    long long arr[n];
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    long long result[n];
    prefix_sum(arr, n, result);
    int start, end;
    for (int i = 0; i < q; i++) {
        cin >> start >> end;
        long long ans;
        if (start == 1) {
            ans = result[end - 1];
        } else {
            ans = result[end - 1] ^ result[start - 2];
        }
        cout << ans << endl;
    }
    return 0;
}