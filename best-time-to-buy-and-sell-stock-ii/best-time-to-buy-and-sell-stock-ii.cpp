class Solution {
public:
    int maxProfit(vector<int>& prices){
        if(prices.size()<1){
            return 0;
        }
        int prev=prices[0];
        int maxP=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<prev){
                //Buy this stock rather
                prev=prices[i];
            }
            else{
                //sell and again purchase the stock
                maxP+=(prices[i]-prev);
                prev=prices[i];
               
            }
        }
        
        return maxP;
        
    }
};