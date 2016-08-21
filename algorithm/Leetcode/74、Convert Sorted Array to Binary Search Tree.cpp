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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
            return sort(nums, 0, nums.size()-1);  
    }
    TreeNode* sort(vector<int>&n, int l, int h)
    {
              if(h<l)
                  return NULL;
              int mid = l+(h-l)/2;
              TreeNode* root = new TreeNode(n[mid]);
              root->right = sort(n, mid+1, h);
              root->left = sort(n, l, mid-1);
              return root;
    }
};
