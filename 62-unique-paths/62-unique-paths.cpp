class Solution {
public:
    
    int fn(int i, int j,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)   return 0;
        
        if(i==0 && j==0) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int left = fn(i,j-1,dp);
        int up = fn(i-1, j,dp);
        
        return dp[i][j] = left+up;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<double>>dp(m+1,vector<double>(n+1,0));
        
        for(int i = 0;i<=m;i++)
            dp[i][0] = 1;
        
        for(int j=0;j<=n;j++) dp[0][j] = 1;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                double left = dp[i][j-1];
                double up = dp[i-1][j];
                
                dp[i][j] = left+up;
            }
        }
        // return fn(m-1,n-1,dp);
        return  (int)dp[m-1][n-1];
    }
};