#include <vector>
#include <iostream>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    vector<int> machines(n);
    for (int i = 0; i < n; i++) {
        cin >> machines[i];
    }
    long long low = 0;
    long long high = 1e18;
    long long answer = 1e18;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long products = 0;
        for (int i = 0; i < n; i++) {
            products += min(mid/machines[i], (long long) 1e9);
        }
        if (products >= m) {
            if (mid < answer) {
                answer = mid;
            }
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    cout << answer;
    return 0;
}