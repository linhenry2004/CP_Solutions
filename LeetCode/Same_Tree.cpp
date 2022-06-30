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
    bool isEqual(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!isEqual(p, q)) {
            return false;
        }
        queue<TreeNode*> Q1, Q2;
        Q1.push(p);
        Q2.push(q);
        
        while (!Q1.empty()) {
            TreeNode* n1 = Q1.front();
            TreeNode* n2 = Q2.front();
            Q1.pop();
            Q2.pop();
            if (!isEqual(n1, n2)) {
                return false;
            }
            if (n1) {
                if (!isEqual(n1->left, n2->left)) {
                    return false;
                }
                if (n1->left) {
                    Q1.push(n1->left);
                    Q2.push(n2->left);
                }
                if (!isEqual(n1->right, n2->right)) {
                    return false;
                }
                if (n1->right) {
                    Q1.push(n1->right);
                    Q2.push(n2->right);
                }
            }
        }
        return true;
    }
};