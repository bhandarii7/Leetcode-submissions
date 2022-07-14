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
        
        vector<vector<int>>ans;
        
        if(!root)
            return ans;
        
        
        int c = 0;
        
        queue<TreeNode*>q;
        stack<TreeNode*>s;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            
            vector<int>v;
            
            if(c%2==0)
            {
                for(int i=0;i<size;i++)
                {
                TreeNode* temp = q.front();
                q.pop();
                
                v.push_back(temp->val);
                
                if(temp->left)
                {
                    q.push(temp->left);
                    s.push(temp->left);
                }
                
                if(temp->right)
                {
                    q.push(temp->right);
                    s.push(temp->right);
                }
                    
                }
                
            }
            else
            {
                while(!s.empty())
                {
                    TreeNode* temp = s.top();
                    s.pop();
                    v.push_back(temp->val);
                    
                    if(q.front()->left)
                        q.push(q.front()->left);
                    if(q.front()->right)
                        q.push(q.front()->right);
                    q.pop();
                }
            }
            ans.push_back(v);
            c++;
        }
        return ans;
    }
};