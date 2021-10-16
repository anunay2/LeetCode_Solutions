class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<int> profitTs1;
        vector<int> profitTs2(prices.size(),0);
        
        int buy = prices[0],profit = 0;
        profitTs1.push_back(profit);
        
        for(int i=1;i<prices.size();i++){
            profit = std::max(profit,prices[i]-buy);
            profitTs1.push_back(profit);
            buy = std::min(buy,prices[i]);
        }
        
        int sell = prices.back();
        profit =0;
        
        for(int i=prices.size()-1;i>=0;i--){
            profit = std::max(profit,sell - prices[i]);
            profitTs2[i] = profit;
            sell = std::max(sell,prices[i]);
        }
        
        int ans =0;
        
        for(int i=1;i<prices.size()-1;i++){
            ans = std::max(ans,profitTs1[i-1] + profitTs2[i]);
        }
        ans = std::max(ans,profitTs2[0]);
        ans = std::max(ans,profitTs1.back());
        return ans;
        
    }
};