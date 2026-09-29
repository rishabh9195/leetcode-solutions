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
    int res=INT_MIN;
    int fun(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int left=max(0,fun(root->left));
        int right=max(0,fun(root->right));

        int  currentPath= root->val + left + right;

        res=max(res,currentPath);

        return (root->val+max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        fun(root);
        return res;
    }
};