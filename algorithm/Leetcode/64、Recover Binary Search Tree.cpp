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
    void recoverTree(TreeNode* root) {
         TreeNode* cur = root, *pre = NULL, *node;
         vector<TreeNode*> res(2,NULL);
         while(cur)
         {
             if(cur->left==NULL)
             {                 
                 test(res, pre, cur);
                 pre = cur;
                 cur = cur->right;
             }
             else
             {
                 node = cur->left;
                 while(node->right!=NULL && node->right !=cur)
                    node = node->right;
                  if(node->right==NULL)
                  {
                      node->right = cur;
                      cur = cur->left;
                  }
                  else 
                  {
                      test(res, pre,cur);
                      node->right = NULL;
                      pre = cur;
                      cur = cur ->right;
                  }
             }
         }
         swap(res[0]->val, res[1]->val);
    }
    void test(vector<TreeNode*> &res, TreeNode* pre, TreeNode* cur)
    {
          if(pre!=NULL &&cur!=NULL &&pre->val>cur->val)
          {
                if(res[0]==NULL)
                     res[0] = pre;
                res[1] = cur;
          }
    }
};
