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
    bool sametree(TreeNode* p,TreeNode* q)
    {
        if(p==NULL && q==NULL)
            return true;
        
        if(p==NULL || q==NULL)
            return false;
        
        if(p->val != q->val)
            return false;
        
        bool r1=sametree(p->left,q->left);
        bool r2=sametree(p->right,q->right);

        return (r1&&r2);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(root==NULL || subRoot==NULL)
            return false;
        
        if(root->val == subRoot->val)
        {
            if(sametree(root,subRoot))
                return true;
        }

        bool l1=isSubtree(root->left,subRoot);
        bool r1=isSubtree(root->right,subRoot);

        return l1 || r1;
            
    }
};