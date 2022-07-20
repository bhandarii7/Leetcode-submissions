class Solution {
public:
    
    void func(vector<int>ds,vector<vector<int>>&ans,vector<int>& nums,vector<int>vis)
    {
        if(nums.size()==ds.size())
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(vis[i]==0)
            {
                ds.push_back(nums[i]);
                vis[i] = 1;
                func(ds,ans,nums,vis);
                ds.pop_back();
                vis[i] = 0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n = nums.size();
        vector<int>vis(n,0);
        
        func(ds,ans,nums,vis);
        
        return ans;
    }
};