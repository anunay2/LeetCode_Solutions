class Solution {
public:
    int rob(vector<int>& nums) {
        
        int prev2 = 0, prev1 =0;
        for(auto num : nums){
            int temp = prev1;
           
            prev1 = max(prev2 + num, prev1);
            prev2 = temp;
        }
        return prev1;
    }
};