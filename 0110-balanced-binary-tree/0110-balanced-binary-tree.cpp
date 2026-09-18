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
    int nodeheight(TreeNode* root)
    {
        if(root==NULL)
            return 0;

        int left= nodeheight(root->left);
        int right= nodeheight(root->right);

        if(abs(left-right)>1)
            return -1;

        if (left == -1 || right == -1)
            return -1;

        return 1+max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        return nodeheight(root) != -1;
    }
};