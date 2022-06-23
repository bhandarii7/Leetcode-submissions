class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     
        vector<vector<int>>ans;
        
        sort(nums.begin(),nums.end());
        
        if(nums.size()<3)
            return {};
        
        if(nums[0]>0)
            return {};
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                break;
            
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            int low = i+1, high = nums.size()-1;
            
            while(low<high)
            {
                int sum = nums[i]+nums[low]+nums[high];
                
                if(sum>0)
                    high--;
                else if(sum<0)
                    low++;
                else
                {
                    ans.push_back({nums[i],nums[low],nums[high]});
                    int lowocc = nums[low],highocc = nums[high];
                    
                    while(low<high&& nums[low]==lowocc)
                        low++;
                    
                    while(low<high&& nums[high]==highocc)
                        high--;
                    
                }
            }
                
        }
        
        return ans;
    }
};