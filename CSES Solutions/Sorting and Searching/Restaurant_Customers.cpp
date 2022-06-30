#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<pair<int, int>> customers;
    for (int i = 0; i < n; i++) {
        int a, b; 
        cin >> a >> b; 
        customers.push_back({a, 1});
        customers.push_back({b, 0});
    }

    sort(customers.begin(), customers.end());

    int count = 0;
    int ans = 0;
    for (auto customer : customers) {
        if (customer.second == 1) {
            count++;
            ans = max(count, ans);
        } else { // customer.second == 0;
            count--;
        }
    }
    cout << ans << endl;
    return 0;
}