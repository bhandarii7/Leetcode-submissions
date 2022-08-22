class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int>fm;
        map<int,int>m;
        
        for(int i=0;i<nums.size();i++)
            fm[nums[i]]++;
        
        for(auto i:nums)
        {
            if(fm[i]==0)
            {
                continue;
            }
            
            fm[i]--;
            
                if(m[i-1]>0)
                {
                    m[i-1]--;
                    m[i]++;
                }
            else
                if(fm[i+1]>0 && fm[i+2]>0)
                {
                    fm[i+1]--;
                    fm[i+2]--;
                    m[i+2]++;
                }
            else
                return false;
        }
        
        return true;
        
        
        
    }
};