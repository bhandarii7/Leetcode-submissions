class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++) vis[i][0]  = matrix[i][0];
        
        for(int j=0;j<m;j++) vis[0][j] = matrix[0][j];
        
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==1)
                    vis[i][j] =1 +  min(vis[i-1][j],min(vis[i-1][j-1],vis[i][j-1]));
            }
        }
        
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cnt+=vis[i][j];
            }
        }
        
        return cnt;
    }
};