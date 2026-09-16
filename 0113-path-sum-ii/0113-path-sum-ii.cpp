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
    vector<vector<int>> res;
    void fun(TreeNode* root, int sum,vector<int>arr,int targetSum)
    {
        if(root==NULL)
            return;

        sum=sum+root->val;
        arr.push_back(root->val);
        
        if(root->left ==NULL && root->right ==NULL)
        {
            if(sum==targetSum)
            {
                res.push_back(arr);
                return;
            }     
        }

        fun(root->left,sum,arr,targetSum);
        fun(root->right,sum,arr,targetSum);

        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>arr;
        fun(root,0,arr,targetSum);
        return res;
    }
};