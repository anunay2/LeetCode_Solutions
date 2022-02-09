class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0,j = 1;
        if(nums.size()<=1){
            return 0;
        }
        unordered_map<int,int> count;
        for(auto num : nums){
            count[num]++;
        }
        int ans = 0,ans1 = 0;
        
        for(auto it : count){
            if(it.second>1){
                ans1++;
            }
            if(count.find(it.first + k)!=count.end()){
                ans++;
            }
        }
        if(k==0){
            return ans1;
        }
        return ans;
    }
};