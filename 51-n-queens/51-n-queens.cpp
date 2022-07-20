class Solution {
public:
    
    
    bool isValid(int row,int col,vector<string>v,int n)
    {
        
        int r = row;
        int c = col;
        
        //upper dia
        while(r>=0 && c>=0)
        {
            if(v[r][c]=='Q')
                return false;
            r--;
            c--;
        }
        
        //left
        r = row;
        c = col;
        
        while( c>=0)
        {
            if(v[r][c]=='Q')
                return false;
            c--;
        }
        
        r = row;
        c = col;
        
        while( r<n && c>=0 )
        {
            if(v[r][c]=='Q')
                return false;
            c--;
            r++;
        }
        
        return true;

    }
    void func(int col,int n, vector<vector<string>> &ans, vector<string>v)
    {
        if(col==n)
        {
            ans.push_back(v);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isValid(row,col,v,n))
            {
                v[row][col] = 'Q';
                func(col+1,n,ans,v);
                v[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>v(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++)
            v[i] = s;
        
        func(0,n,ans,v);
        
        return ans;
    }
};