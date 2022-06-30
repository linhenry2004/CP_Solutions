#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Case #" << i << ": " << endl;
        int R, C; 
        cin >> R >> C; 
        string even, odd;

        for (int j = 0; j < C; j++) {
            even += "+-";
            odd += "|.";
        }

        even += "+";
        odd += "|";

        for (int j = 0; j <= 2 * R; j++) {
            string row = j % 2 == 0 ? even : odd;

            if (j <= 1) {
                row = ".." + row.substr(2);
            }

            cout << row << endl;
        }
    }
    return 0;
}