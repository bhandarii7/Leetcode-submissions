class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        int carry = 1;
        
        vector<int>ans;
        
        if(digits[n-1]<9)
        {
            digits[n-1]+=1;
            return digits;
        }
        
        
        for(int i=n-1;i>=0;i--)
        {
            if(digits[i]==9 && carry==1)
            {
                ans.push_back(0);
            }
            else
            {
                digits[i] += carry;
                ans.push_back(digits[i]);
                carry = 0;
            }
        }
        
        if(carry)
            ans.push_back(1);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};