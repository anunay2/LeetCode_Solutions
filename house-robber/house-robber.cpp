class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> maxMoneyEndingThisHouse (nums.size());
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            maxMoneyEndingThisHouse[i] = nums[i];
            for(int j=i-2;j>=0;j--){
                maxMoneyEndingThisHouse[i] = max(            maxMoneyEndingThisHouse[i] ,maxMoneyEndingThisHouse[j] + nums[i]);
            }
            ans  = max(maxMoneyEndingThisHouse[i],ans);
        }
        return ans;
    }
};