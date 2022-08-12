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
    
    bool fn(TreeNode* root,long maxi, long mini)
    {
        if(!root) return true;
        
        if(root->val>=maxi || root->val<=mini)
            return false;
        
        bool left = fn(root->left,root->val,mini);
        bool right = fn(root->right,maxi,root->val);
        
        return left && right;
        
    }
    bool isValidBST(TreeNode* root) {
        return fn(root,LONG_MAX, LONG_MIN);
    }
};