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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(root == nullptr) {
            return {};
        }       
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            
            while (size--) {
                TreeNode* n = q.front();
                q.pop();
                
                temp.push_back(n->val);
                if (n->left) {
                    q.push(n->left);
                }
                if (n->right) {
                    q.push(n->right);
                }
            }
            res.push_back(temp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};