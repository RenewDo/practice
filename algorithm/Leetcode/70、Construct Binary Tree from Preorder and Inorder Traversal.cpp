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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return tree(preorder,0, preorder.size(), inorder, 0, inorder.size());
    }
    TreeNode* tree(vector<int>& preorder,int pb, int pe, vector<int>& inorder, int ib, int ie)
    {
        if(pb>=pe || ib>=ie)
             return NULL;
         TreeNode* root = new TreeNode(preorder[pb]);
         int i;
         for(i= ib; i<ie; i++)
             if(inorder[i]==preorder[pb])
                  break;
        root->left = tree(preorder,pb+1, pb+i-ib+1, inorder, ib, i);
        root->right = tree(preorder,pb+i-ib+1, pe, inorder, i+1, ie);
        return root;
    }
};
