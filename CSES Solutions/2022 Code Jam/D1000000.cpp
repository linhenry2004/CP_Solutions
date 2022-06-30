#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main () {
    int test_case;
    cin >> test_case;
    for (int i = 1; i <= test_case; i++) {
        cout << "Case #" << i << ": ";
        int n;
        cin >> n;
        vector <int> a(n);
        
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        sort(a.begin(), a.end());

        int ans = 1;
        
        while (ans <= a.size()) {
            if (ans <= a[ans - 1]) {
                ans++;
                continue;
            }
            a.erase(a.begin() + ans - 1);
        }
        cout << a.size() << endl;
    }
    return 0;
}