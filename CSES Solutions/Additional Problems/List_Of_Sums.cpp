#include <bits/stdc++.h>
using namespace std;

array<int, 104> A;
vector<int> B;

bool gen (int n, int a1a2) {
    int a0ai;
    multiset<int> BB;

    for (int b : B) {
        BB.insert(b);
    }

    A[0] = (B[0] + B[1] - a1a2) / 2;
    A[1] = B[0] - A[0];
    A[2] = B[1] - A[0];
    BB.erase(BB.find(B[0]));
    BB.erase(BB.find(B[1]));
    BB.erase(BB.find(a1a2));

    for (int i = 3; i < n; i++) {
        a0ai = *BB.begin();
        A[i] = a0ai - A[0];
        for (int j = 0; j < i; j++) {
            if (BB.find(A[i] + A[j]) == BB.end()) {
                return 0;
            }
            BB.erase(BB.find(A[i] + A[j]));
        }
    }

    for (int i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) return 0;
    }
    return 1;
}

signed main () {
    int n, b;
    cin >> n;

    for (int i = 0; i < n * (n - 1) / 2; i++) {
        cin >> b;
        B.push_back(b);
    }
    
    sort(B.begin(), B.end());
    for (int i = 2; i <= n; i++) {
        if (gen(n, B[i])) {
            for (int j = 0; j < n; j++) {
                cout << A[j] << " ";
            }
            break;
        }
    }
    
    cout << endl;
    return 0;
}