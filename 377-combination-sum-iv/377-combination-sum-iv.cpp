class Solution {
public:
    
    int fn(int tar,int n, vector<int>&a,vector<int>&dp)
    {
        if(tar==0) return 1;
        
        if(tar<0) return 0;
        
        if(dp[tar]!=-1) return dp[tar];
        
        int total = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(tar>= a[i])
            total+= fn(tar-a[i],n,a,dp);
        }
        
        return dp[tar] =  total;
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int>dp(target+1,-1);
        return fn(target,n,nums,dp);
    }
};