class Solution {
public:
    
    void dfs(int i, vector<int>&vis,vector<int>adj[])
    {
        vis[i] = 1;
        
        for(auto it:adj[i])
        {
            if(!vis[it])
                dfs(it,vis,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        
        vector<int> adj[V];
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int>vis(V,0);
        
        int c = 0;
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                c++;
                dfs(i,vis,adj);
            }
        }
        
        return c;
    }
};