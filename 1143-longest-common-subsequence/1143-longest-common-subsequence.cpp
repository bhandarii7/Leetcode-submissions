class Solution {
public:
    
    int fn(int i, int j, string &s1, string &s2,vector<vector<int>>&dp)
    {
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j])
            return 1+fn(i-1,j-1,s1,s2,dp);
        
        int left = fn(i-1,j,s1,s2,dp);
        int right = fn(i,j-1,s1,s2,dp);
        
        return dp[i][j] =  max(left,right);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                {
                    
                    int left = dp[i-1][j];
                    int right = dp[i][j-1];

                     dp[i][j] =  max(left,right);
                }
            }
        }
        
        return dp[n][m];
    }
};