#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    string str;
    cin >> str;
    vector<string> v;
    sort(str.begin(), str.end());

    do {
        v.push_back(str);
    } while (next_permutation(str.begin(), str.end()));

    cout << v.size() << endl;

    for (string it : v) {
        cout << it << endl;
    }

    return 0;
}