class Solution {
public:
    
    bool fn(int ind, int tar, vector<int>&arr,vector<vector<int>>&dp)
    {
        if(tar==0) return 1;
        if(ind==0)
        {
            if(arr[ind]==tar)
                return 1;
            
            return 0;
        }
        
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        
        int nt = fn(ind-1,tar,arr,dp);
        int t =0;
        if(tar>=arr[ind])
            t+=fn(ind-1,tar-arr[ind],arr,dp);
        
        return dp[ind][tar] =  t or nt;
        
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++)
            total+=nums[i];
        
        if(total%2!=0) return false;
        
        vector<vector<int>>dp(n,vector<int>(total,-1));
        
        return fn(n-1,total/2,nums,dp);
    }
};