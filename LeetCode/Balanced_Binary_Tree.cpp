#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool result = true;
    bool isBalanced(TreeNode* root) {
        validate(root);
        return result;
    }
    int validate (TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = validate(root->left);
        int right = validate(root->right);
        if (abs(left - right) > 1) {
            result = false;
        }
        return 1 + max(left, right);
    }
};