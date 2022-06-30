#include <vector>
#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it: v) cin>>it;
    // for (int x: v) cout << x << " ";
    // cout << endl;

    const int maxa = 100;
    vector<int> cnt(maxa, 0);
    for (auto it: v) cnt[it]++;
    // for (int y: cnt) cout << y << " ";
    // cout << endl;

    vector<int> ans(n);
    int id = 0;
    for (int i = 0; i < maxa; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            ans[id] = i;
            id++;
        }
    }
    for (auto it: ans) cout << it << ' ';
    cout << endl;

    return 0;
}