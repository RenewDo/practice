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
    bool isBalanced(TreeNode* root) {
         return height(root)>=0;
    }
    int height(TreeNode* root)
    {
        if(!root)
           return 0;
        int left = height(root->left);
        int right = height(root->right);
        if(left<0 || right<0 || abs(left-right)>1)
            return -1;
        return max(left,right)+1;
    }
};
