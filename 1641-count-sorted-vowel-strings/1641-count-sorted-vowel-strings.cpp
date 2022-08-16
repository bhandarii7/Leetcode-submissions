class Solution {
public:
    
    int fn(int size, int val, int n, vector<vector<int>>&dp)
    {
        if(size==n) return 1;
        
        if(dp[size][val]!=-1) return dp[size][val];
        
        int count = 0;
        
        for(int i=val; val<5;val++)
        {
            count+= fn(size+1,val,n,dp);
        }
        
        return  dp[size][val] = count; 
    }
        
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n+1,vector<int>(6,-1));
        return fn(0,0,n,dp);
    }
};