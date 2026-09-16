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
    int res=0;
    void fun(TreeNode* root, int sum,int& res)
    {
        if(root==NULL)
            return;

        sum=sum*10+root->val;
        
        if(root->left ==NULL && root->right ==NULL)
        {
            res=res+sum;
        }

        fun(root->left,sum,res);
        fun(root->right,sum,res);

        return;
    }

    int sumNumbers(TreeNode* root) {
        fun(root,0,res);
        return res;
    }
};