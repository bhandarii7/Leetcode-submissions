class Solution {
public:
    
    void func(int ind,int n,vector<int>ds,vector<vector<int>>&ans,vector<int>& nums)
    {
        if(ind==n)
        {
            ans.push_back(ds);
            return;
        }
        
        for(int j=ind;j<n;j++)
        {
            swap(nums[ind],nums[j]);
            ds.push_back(nums[ind]);
            
            func(ind+1,n,ds,ans,nums);
            swap(nums[ind],nums[j]);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n = nums.size();
        func(0,n,ds,ans,nums);
        
        return ans;
    }
};