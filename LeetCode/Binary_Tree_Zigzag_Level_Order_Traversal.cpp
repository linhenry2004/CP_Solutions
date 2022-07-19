#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        deque<TreeNode *> Q;
        Q.push_back(root);
        bool reverse = true;
        while (!Q.empty()) {
            int count = Q.size();
            vector<int> level;
            deque<TreeNode *> DQ;
            for (int i = 0; i < count; i++) {
                TreeNode* n = Q.front();
                level.push_back(n->val);
                Q.pop_front();
                if (reverse) {
                    if (n->left) {
                        DQ.push_front(n->left);
                    }
                    if (n->right) {
                        DQ.push_front(n->right);
                    }
                } else {
                    if (n->right) {
                        DQ.push_front(n->right);
                    }
                    if (n->left) {
                        DQ.push_front(n->left);
                    }
                }
            }
            Q.insert(Q.end(), DQ.begin(), DQ.end());
            res.push_back(level);
            reverse = !reverse;
        }
        return res;
    }
};