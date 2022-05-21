class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i = nums.size()-2;
        int j = i+2;
        
        while(i>=0 && nums[i]>=nums[i+1] )
        {
            i--;
        }
        
        if(i<0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        while(nums[--j]<=nums[i]);
        
        swap(nums[i],nums[j]);
        
        sort(nums.begin()+i+1,nums.end());
    }
};