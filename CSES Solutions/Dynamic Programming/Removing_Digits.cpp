#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9

int main () {
    int n;
    cin >> n;
    vector<int> minSteps (n + 1, INF);
    minSteps[0] = 0;
    for (int val = 1; val <= n; val++) {
        int temp = val;
        while (temp > 0) {
            minSteps[val] = min(minSteps[val],minSteps[val - temp % 10] + 1);
            temp /= 10;
        }
    }
    cout << minSteps[n];
}