class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
       int dp[nums.size()];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans= max(dp[i],ans);
        }
        return ans;
        
    }
};