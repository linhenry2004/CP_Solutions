#include <iostream>
#include <vector>
using namespace std;

int f (int n) {
    if (n <= 1) {
        return 1;
    }
    int count = 0;
    for (int i = 1; i <= 6; i++) {
        if (n - i >= 0) {
            int temp = f(n - i);
            count += temp;
        }
    }
    return count;
}

int main () {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}