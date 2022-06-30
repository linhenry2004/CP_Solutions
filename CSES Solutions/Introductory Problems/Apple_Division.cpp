#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

ll totalSum = 0;
 
ll findMin (ll arr[], int n, ll currSum) {
    if (n == 0 || currSum >= totalSum / 2) {
        return abs((totalSum - currSum) - currSum);
    }
 
    return min(findMin(arr, n - 1, currSum + arr[n - 1]), findMin(arr, n - 1, currSum));
}
 
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totalSum += arr[i];
    }
    cout << findMin(arr, n - 1, arr[n - 1]) << endl;
    return 0;
}