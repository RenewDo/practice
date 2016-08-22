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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return minD(root, 1);
    }
    int minD(TreeNode* root, int dep)
    {
        if(root->left && root->right)
        return min(minD(root->left, dep+1),minD(root->right, dep+1));
        else if(root->left)
        return  minD(root->left, dep+1);
        else if(root->right)
        return minD(root->right, dep+1);
        return dep;
    }
};
