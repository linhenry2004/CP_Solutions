#include <iostream>
using namespace std;

#define ll long long

const int INF = 1e9 + 7;

int main () {
    ll n, s = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        s *= 2;
        s %= INF;
    }
    cout << s << endl;
    return 0;
}