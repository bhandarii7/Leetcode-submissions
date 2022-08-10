class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>temp;
        
        for(int i=0;i<=n;i++ )
        {
            int sum = 0;
            
            int num = i;
            
            while(num!=0)
            {
                sum+= num%2;
                num = num/2;
            }
            temp.push_back(sum);
        }
        
        return temp;
    }
};