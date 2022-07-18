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
    
    int func(TreeNode* root, int &maxm)
    {
        if(!root)
            return 0;
        
        int l = max(0,func(root->left,maxm));
        int r = max(0,func(root->right,maxm));
        
        maxm = max(maxm,l+r+root->val);
        
        return max(l,r)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        
        int maxm = INT_MIN;
        func(root,maxm);
        
        return maxm;
    }
};