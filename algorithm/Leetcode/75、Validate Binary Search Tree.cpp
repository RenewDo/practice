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
    bool isValidBST(TreeNode* root) {
         long long l = (long long)INT_MIN -1;
         long long h = (long long)INT_MAX +1;
         return isBST(root, l, h);
    }
    bool isBST(TreeNode* r, long long l, long long h)
    {
         if(r==NULL)
             return true;

         return r->val< h && r->val >l && isBST(r->left, l, r->val) && isBST(r->right, r->val, h);
    }
};
