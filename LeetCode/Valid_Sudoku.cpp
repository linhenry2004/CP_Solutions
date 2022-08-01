#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            bool rows[9] = {false};
            bool cols[9] = {false};
            bool blocks[9] = {false};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (rows[board[i][j] - '1']) {
                        return false;
                    }
                    rows[board[i][j] - '1'] = true;
                }
                if (board[j][i] != '.') {
                    if (cols[board[j][i] - '1']) {
                        return false;
                    }
                    cols[board[j][i] - '1'] = true;
                }
                if (board[((i / 3) * 3 + j / 3)][((i % 3) * 3) + j % 3] != '.') {
                    if (blocks[board[((i / 3) * 3 + j / 3)][((i % 3) * 3) + j % 3] - '1']) {
                        return false;
                    }
                    blocks[board[((i / 3) * 3 + j / 3)][((i % 3) * 3) + j % 3] - '1'] = true;
                }
            }
        }
        return true;
    }
};