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
    int combinationSum4(vector<int>& a, int target) {
        
        int n = a.size();
        vector<double>dp(target+1,0);
        
        dp[0] = 1;
        
        int total = 0;
        for(int i=1;i<=target;i++)
        {
                 double total = 0;
            for(int j=0;j<n;j++)
            {
                if(i>= a[j])
                total+= dp[i-a[j]];
            }
        
            dp[i] =  total;
        }
        // return fn(target,n,a,dp);
        
        return (int)dp[target];
    }
};