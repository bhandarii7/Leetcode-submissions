class Solution {
public:
    
    int fn(int ind, string &s, int n,vector<int>&dp)
    {
        if(ind >n ) return 1;
        if(s[ind]=='0') return 0;
        
        string b = s.substr(ind,2);
        
        if(dp[ind]!=-1) return dp[ind];
        int one = fn(ind+1,s,n,dp);
        int two = 0;
        if(ind != n && stoi(b)<=26&&stoi(b)>0)
        two += fn(ind+2,s,n,dp);
        
        return dp[ind] = one + two;
    }
    int numDecodings(string s) {
        
        if(s[0]=='0') return 0;
        int n = s.size();
        vector<int>dp(n+1,-1);
        
        return fn(0,s,n-1,dp);
    }
};