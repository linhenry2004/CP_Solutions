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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        vector<vector<int>> res;
        queue<TreeNode *> nodes;
        
        nodes.push(root);
        nodes.push(nullptr);
        vector<int> level;
        
        while (!nodes.empty()) {
            TreeNode *node = nodes.front();
            nodes.pop();
            
            if (node) {
                level.push_back(node->val);
                
                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
            } else {
                res.push_back(level);
                level.clear();
                if (!nodes.empty()) {
                    nodes.push(nullptr);
                }
            }
        }
        return res;
    }
};