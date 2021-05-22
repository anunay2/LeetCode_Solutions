class Solution {
public:
    int maxProfit(vector<int>& prices){
        if(prices.size()==0){
            return 0;
        }
        int ans=0,min1=prices[0];
        for(int i=1;i<prices.size();i++){
            min1=min(prices[i],min1);
            if(prices[i]>min1){
                ans=max(ans,prices[i]-min1);
            }
        }
        return ans;
        
    }
};