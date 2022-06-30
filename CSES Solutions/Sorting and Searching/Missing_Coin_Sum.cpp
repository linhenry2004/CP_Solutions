#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll smallestSum = 1;
    for (int i = 0; i < n; i++) {
        if (smallestSum >= a[i]) {
            smallestSum += a[i];
        }
    }
    cout << smallestSum << endl;
}