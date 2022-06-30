#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define ll long long

int main () {
    int n;
    cin >> n;

    vector<ll> power(19, 1);
    for (int i = 1; i < 19; i++) {
        power[i] = power[i - 1] * 10;
    }

    for (int count = 0; count < n; count++) {
        ll m;
        cin >> m;
        ll curr = 0;
        ll prev = 0;
        int num = 0;
        for (int i = 1; i <= 18; i++) {
            curr += (power[i] - power[i - 1]) * i;
            if (curr >= m) {
                num = i;
                break;
            }
            prev += (power[i] - power[i - 1]) * i;
        }

        ll min = power[num - 1];
        ll max = power[num] - 1;
        ll best = 0;
        ll start = 0;
        
        while (min <= max) {
            ll actual = (min + max) / 2;
            ll startA = prev + 1 + (actual - power[num - 1]) * num;

            if (startA <= m) {
                if (actual > best) {
                    best = actual;
                    start = startA;
                }
                min = actual + 1;
            } else {
                max = actual - 1;
            }
        }
        string number = to_string(best);
        cout << number[m - start] << endl;
    }
    return 0;
}