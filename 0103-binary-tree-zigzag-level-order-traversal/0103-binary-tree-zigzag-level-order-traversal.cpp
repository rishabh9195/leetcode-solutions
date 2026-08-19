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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>>res;
        if(root == NULL)
            return res;
            
        q.push(root);
        bool lefttoright=true;

        while(!q.empty())
        {
            int levelsize= q.size();
            vector<int> temp(levelsize);
            for (int i = 0; i < levelsize; i++)
            {
                TreeNode* t=q.front();
                q.pop();

                if(lefttoright)
                {
                    temp[i]=t->val;
                }
                else
                {
                    temp[levelsize-1-i]=t->val;
                }
                
                if(t->left != NULL)
                    q.push(t->left);

                if(t->right != NULL)
                    q.push(t->right);  
            }
            res.push_back(temp);
            lefttoright=!lefttoright;
        }
        return res;
    }
};