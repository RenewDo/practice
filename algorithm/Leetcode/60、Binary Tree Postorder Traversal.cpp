
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> in;
        TreeNode* l=root, *r;
        do
        {
            while(l)
            {
                in.push(l);
                l = l ->left;
            }
            r = NULL;
            while(!in.empty())
            {
                l = in.top();
                in.pop();
                if(l->right==r)
                {
                    res.push_back(l->val);
                    r = l;
                }
                else 
                {
                   in.push(l);
                   l = l->right;
                   break;
                }
            }
            
        }while(!in.empty());
        return res;
    }  
};
