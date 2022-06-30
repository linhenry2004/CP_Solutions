#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main () {
    int x, n;
    cin >> x >> n;
    set<int> a;
    multiset<int> b;
    a.insert(0);
    a.insert(x);
    b.insert(x - 0);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.insert(temp);
        auto iter = a.find(temp);
        int front = *prev(iter);
        int back = *next(iter);
        b.erase(b.find(back - front));
        b.insert(temp - front);
        b.insert(back - temp);
        cout << *b.rbegin() << endl;
    }
    return 0;
}