#include <iostream>
using namespace std;

void prefix_sum (int arr[], int n, int result[]) {
    result[0] = arr[0];
    for (int i = 1; i < n; i++) {
        result[i] = result[i - 1] + arr[i];
    }
}

int main () {
    int n; 
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    int result[n];
    prefix_sum(arr, n, result);
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    return 0;
}