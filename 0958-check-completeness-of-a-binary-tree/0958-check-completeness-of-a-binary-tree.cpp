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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)
            return true;

        bool nullseen=false;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* t= q.front();
            q.pop();

            if(t==NULL)
                nullseen=true;
            
            else{
                if(nullseen==true)
                    return false;
                
                q.push(t->left);
                q.push(t->right);
            }

        }
        return true;
    }
};