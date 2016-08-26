
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
    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        findMax(root, val);
        return val;
    }
    int findMax(TreeNode* root, int &val)
    {
         if(root==NULL)
           return 0;
        int left = findMax(root->left, val);
        int right = findMax(root->right, val);
        if(left+right+root->val > val)
            val = left+right+root->val;
        int maxV = max(left, right);
        if(maxV<0)
        {
            if(root->val<0)
              return 0;
            else
            {
                if(root->val > val)
                val = root->val;
                return root->val;
            }
        }
        else 
        {
            if(maxV+root->val<0)
               return 0;
            else 
            {
                if(maxV+root->val > val)
                   val =  maxV+root->val;
                return maxV+root->val;
            }
        }
    }
};
