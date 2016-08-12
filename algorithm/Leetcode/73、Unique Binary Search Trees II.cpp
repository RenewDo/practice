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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
           if(n==0)
               return  res;
           return gene(1,n);
    }
    vector<TreeNode*> gene(int a, int b)
    {
        vector<TreeNode*> res;
        if(a>b)
        {
            res.push_back(NULL);
            return res;
        }
        for(int tmp=a; tmp<=b; tmp++ )
        {
          vector<TreeNode*> left = gene(a, tmp-1);
          vector<TreeNode*> right = gene(tmp+1, b);
          for(auto i:left)
            for(auto j:right)
            {
                TreeNode *root = new TreeNode(tmp);
                root->left = i;
                root->right = j;
                res.push_back(root);
            }
        }
        return  res;
    }
};
