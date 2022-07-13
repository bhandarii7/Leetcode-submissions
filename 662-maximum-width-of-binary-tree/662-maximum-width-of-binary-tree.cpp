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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int ans = 0;
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        
        while(!q.empty())
        {
            int mn ;
            int mx ;
            int mini = q.front().second;
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front().first;
                int curri = q.front().second - mini+1;
                
                q.pop();
                
                if(i==0)
                    mn = curri;
                
                if(i==size-1)
                    mx = curri;
                
                if(node->left)
                    q.push({node->left,2LL*curri});
                
                if(node->right)
                    q.push({node->right,2LL*curri +1});
            }
            
            ans = max(ans,mx-mn+1);
        }
        
        return ans;
    }
};