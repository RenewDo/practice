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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
                return tree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    TreeNode* tree(vector<int>& in,int ib, int ie, vector<int>& po, int pb, int pe)
    {
        if(ib>=ie || pb>=pe)
            return NULL;
        TreeNode* root = new TreeNode(po[pe-1]);
        int i=ib;
        while(i<ie)
        {
            if(in[i]==po[pe-1])
            break;
            else i++;
        }
        root->left = tree(in, ib, i, po, pb, pb+i-ib);
        root->right = tree(in, i+1, ie, po, pb+i-ib, pe-1);
        return root;
    }
};
