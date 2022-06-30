#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

bool duplicate (vector <int> cnt, bool isOdd) {
    int num = 0;
    for (auto it : cnt) {
        if (!isOdd && it % 2 == 1) {
            return false;
        }
        else if (isOdd && it % 2 == 1) {
            num++;
            if (num >= 2) {
                return false;
            } else {
                continue;
            }
        }
    }
    return true;
}

int main () {
    string str, ans;
    cin >> str;
    bool isOdd = str.length() % 2 == 1;
    vector <int> cnt(26, 0);
    int asc;
    for (int i = 0; i < str.length(); i++) {
        asc = str[i] - 65;
        cnt[asc]++;
    }
    bool solvable = duplicate(cnt, isOdd);
    if (!solvable) {
        cout << "NO SOLUTION" << endl;
        return 0;
    } else {
        char mid;
        for (int i = 0; i < 26; i++) {
            char temp = char(i + 65);
            int num = cnt[i];
            if (num % 2 == 1) {
                mid = temp;
            }
            num /= 2;
            for (int j = 0; j < num; j++) {
                ans.push_back(temp);
            }
        }
        if (isOdd) {
            string rev = ans;
            reverse(ans.begin(), ans.end());
            ans.push_back(mid);
            ans += rev;
        } else {
            string rev = ans;
            reverse(ans.begin(), ans.end());
            ans += rev;
        }
        cout << ans << endl;
    }
    return 0;
}