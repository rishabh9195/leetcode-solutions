/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int fun(TreeNode* root, int maxval)
    {
        if(root==NULL)
        {
            return 0;
        }
        int count=0;
        if(root->val>=maxval)
        {
            maxval=root->val;
            count=1;
        }
        

        count+=fun(root->left,maxval);
        count+=fun(root->right,maxval);

        return count;
    }
    int goodNodes(TreeNode* root) {
       return fun(root,INT_MIN);
    }
};