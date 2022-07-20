class Solution {
public:
    void fun(map<vector<int>,vector<int>>&ans,vector<int>ds,vector<int>nums,int i,int n)
    {
        if(i==n)
        {
            sort(ds.begin(),ds.end());
            ans.insert({ds,ds});
            return;
        }
        
        
        ds.push_back(nums[i]);
        fun(ans,ds,nums,i+1,n);
        
        ds.pop_back();
        fun(ans,ds,nums,i+1,n);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<vector<int>,vector<int>>ans;
        vector<int>ds;
        fun(ans,ds,nums,0,nums.size());
        
        vector<vector<int>>v;
        
        for(auto it: ans)
        {
            v.push_back(it.second);
        }
        return v;
    }
};