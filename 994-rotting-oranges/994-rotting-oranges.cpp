class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int vis[n][m];
        
        queue<pair<pair<int,int>,int>>q;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
                else
                    vis[i][j] = 0;     
            }
        }
        
        int time = 0;
        
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            int r= q.front().first.first;
            int c= q.front().first.second;
            int tm = q.front().second;
            
            time = max(tm,time);
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2)
                {
                    vis[nrow][ncol] = 2;
                    q.push({{nrow,ncol},tm+1});
                }
            }
            
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]!=2 && grid[i][j]==1)
                    return -1;
            }
        }
        
        return time;
    }
};