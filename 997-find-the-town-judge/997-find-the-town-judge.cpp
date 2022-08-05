class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool>vis(n+1,false);
        
        int m = trust.size();
        
        for(int i=0;i<m;i++)
        {
            vis[trust[i][0]] = true;
        }
        
        int trustNo = 0;
        
        for(int i = 1;i<=n;i++)
            if(vis[i]==false) 
                trustNo = i;
        
        int count =0;
        
        for(int i=0;i<m;i++)
        {
            if(trust[i][1]==trustNo)
                count++;
        }
        
        if(count==n-1)
            return trustNo;
        else
            return -1;
    }
};