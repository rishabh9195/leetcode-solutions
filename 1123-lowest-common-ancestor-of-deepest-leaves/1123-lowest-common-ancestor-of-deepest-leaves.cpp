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
    int maxdepth=0;
    vector<TreeNode*> deepestleaves;
    TreeNode* ans=NULL;

    int fun(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if(node==NULL)
            return 0;

        int left=fun(node->left,p,q);
        int right=fun(node->right,p,q);

        int self=0;
        if(node==p || node==q)
            self=1;

        int total= left+right+self;

        if(total==2 && ans==NULL)
        {
            ans=node;
        }

        return total;
        
    }
    void solve(TreeNode* root, int depth) {
    if(root->left==NULL && root->right==NULL)
    {
        if(depth>maxdepth)
    {
        maxdepth=depth;
        deepestleaves.clear();
        deepestleaves.push_back(root);
    }
    else if(depth==maxdepth)
    {
        deepestleaves.push_back(root);
    }
    return;
    }

    if(root->left != NULL)
        solve(root->left,depth+1);

    if(root->right != NULL)
        solve(root->right,depth+1);
}

    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        ans = NULL;

        fun(root, p, q);

        return ans;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        solve(root,0);

        TreeNode* result= deepestleaves[0];

        for(int i=1; i<deepestleaves.size();i++)
        {
            result=lca(root,result,deepestleaves[i]);
        }
        return result;
    }
};