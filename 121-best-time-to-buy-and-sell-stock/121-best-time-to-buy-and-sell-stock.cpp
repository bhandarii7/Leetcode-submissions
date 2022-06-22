class Solution {
public:
    int maxProfit(vector<int>& prices) {
            
        int profit = 0;
        int buy = INT_MAX;
        
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i]<buy)
                buy = prices[i];
            
            int j = i+1;
            
            profit = max(prices[j]-buy,profit);
        }
        
        return profit;
        
    }
};