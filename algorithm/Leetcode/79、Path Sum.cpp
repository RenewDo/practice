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
    bool hasPathSum(TreeNode* root, int sum) {
         if(!root)
            return false;
         return has(root, root->val, sum);
    }
    bool has(TreeNode* root, int cur, int sum)
    {
  
           if(root->left && root->right)
             return has(root->left, cur+root->left->val, sum)||has(root->right, root->right->val+cur, sum);
          else if(root->left)
              return has(root->left, cur+root->left->val, sum);
          else if(root->right)
              return has(root->right, cur+root->right->val, sum); 
          //return true;
          return sum==cur;
       
    }
};
