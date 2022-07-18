#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
map<string, int> mp2;
string name[1001];
int num[1001];

int main () {
    int n;
    cin >> n;
    int max = -0x7f7f;
    string maxName;
    for (int i = 0; i < n; i++) {
        cin >> name[i] >> num[i];
        mp[name[i]] += num[i];
    }
    map<string, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        if (it->second > max) {
            max = it->second;
        }
    }
    for (int i = 0; i < n; i++) {
        if (mp[name[i]] == max) {
            mp2[name[i]] += num[i];
            if (mp2[name[i]] >= max) {
                cout << name[i] << endl;
                break;
            }
        }
    }
    return 0;
}