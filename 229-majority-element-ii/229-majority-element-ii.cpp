class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++)
            m[nums[i]]++;
        
        int lim = n/3;
        vector<int>ans;
        
        for(auto it:m)
        {
            if(it.second>lim)
                ans.push_back(it.first);
        }
        
        return ans;
        
    }
};