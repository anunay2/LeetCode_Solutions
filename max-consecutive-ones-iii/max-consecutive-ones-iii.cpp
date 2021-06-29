class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,ans = 0,n = nums.size();
        while(i<n && j<n){
            if(nums[j]==1){
                j++;
            }
            else if(nums[j]==0 && k>0){
                k--;
                j++;
            }
            else if(nums[j]==0 && k==0){
                //i to j-1 would be our subarray here we update the answer
                ans = max(ans,j-i);
                // bring our first pointer to the positon after first 0
                while(nums[i]!=0){
                    i++;
                }
                i++;
                //since we have overriden the first 0 .so we increase the value of k
                k++;
            }
        }
        //we update the answer again as it might not have been updated yet
        ans = max(ans,j-i);
        return ans;
        
    }
};