#include <iostream>
#include <map>
using namespace std;

int main () {
    int n;
    long long target;
    cin >> n >> target;
    map<long long, long long> mp;
    for (int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        if (mp.count(target - temp)) {
            cout << i + 1 << " " << mp[target - temp] << endl;
            return 0;
        }
        mp.insert({temp, i + 1});
    }
    cout << "IMPOSSIBLE";
    return 0;
}