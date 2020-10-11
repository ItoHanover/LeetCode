class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size() == 0)
            return 0;
        
        int profit = 0;
        int mintemp = prices[0];
        for(int i = 0; i < prices.size(); i ++)
        {
            mintemp = min(mintemp,prices[i]);
            profit = max(prices[i] - mintemp,profit);
        }
        
        return profit;
    }
};