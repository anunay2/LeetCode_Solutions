class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int max_run=1,run=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]+1==nums[i] ){
                run++;
            }
            else if(nums[i]!=nums[i-1]){
                run=1;
            }
            max_run=max(max_run,run);
        }
        return max_run;
    }
};