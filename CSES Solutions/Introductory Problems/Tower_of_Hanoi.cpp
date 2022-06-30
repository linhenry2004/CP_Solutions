#include <iostream>
using namespace std;

#define ll long long

void solve (int src, int dest, int aux, int n) {
    if (n <= 0) {
        return;
    }
    solve(src, aux, dest, n - 1);
    cout << src << " " << dest << endl;
    solve (aux, dest, src, n - 1);
}

int main () {
    int n;
    cin >> n;
    cout << (1<<n) - 1 << endl;
    solve (1, 3, 2, n);
    return 0;
}