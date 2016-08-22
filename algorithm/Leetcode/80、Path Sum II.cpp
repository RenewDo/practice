/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
         vector<vector<int>> res;
         if(!root)
            return res;
         vector<int> cur;
         cur.push_back(root->val);
         return path(root, res, sum-root->val, cur);
    }
    vector<vector<int>> path(TreeNode* root, vector<vector<int>> &res, int sum, vector<int>cur)
    {
           if(root->left)
           {
               cur.push_back(root->left->val);
               path(root->left, res, sum-root->left->val, cur); 
           }
           if(root->right)
           {
               if(root->left)cur.pop_back();
               cur.push_back(root->right->val);
              path(root->right, res, sum-root->right->val, cur);              
           }
           if(sum == 0 && !root->left && !root->right)
            res.push_back(cur);
            return res;
           
    }
};
