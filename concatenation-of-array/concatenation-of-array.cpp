class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> conarr(2*n);
        for(int i = 0 ;i<n;i++){
            conarr[i] = nums[i];
            conarr[i+n] = nums[i];
        }
        return conarr;
    }
};