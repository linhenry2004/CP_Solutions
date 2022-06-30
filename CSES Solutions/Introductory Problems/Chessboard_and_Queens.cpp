#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main () {
    vector<string> chessboard(8);
    for (int i = 0; i < 8; i++) {
        cin >> chessboard[i];
    }
    int count = 0;
    vector<int> columns(8);
    for (int i = 0; i < 8; i++) {
        columns[i] = i;
    }
    do {
        bool valid = true;
        for (int i = 0; i < 8; i++) {
            if(chessboard[i][columns[i]] != '.') {
                valid = false;
                break;
            }
        }
        vector<bool> diagonal(15, false);
        for (int i = 0; i < 8; i++) {
            if (diagonal[i + columns[i]]) {
                valid = false;
            }
            diagonal[i + columns[i]] = true;
        }
        for (int i = 0; i < 15; i++) {
            diagonal[i] = false; 
        }
        for (int i = 0; i < 8; i++) {
            if (diagonal[i + 7 - columns[i]]) {
                valid = false;
            }
            diagonal[i + 7 - columns[i]] = true;
        }
        count += valid;
    } while (next_permutation(columns.begin(), columns.end()));
    cout << count << endl;
    return 0;
}