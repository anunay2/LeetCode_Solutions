class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            int sum=-nums[i];
            int s=i+1,e=nums.size()-1;
            while(s<e){
                if(nums[s]+nums[e]==sum){
                    ans.insert({nums[i],nums[s],nums[e]});
                    s++;
                    e--;
                }
                else if(nums[s]+nums[e]<sum){
                    s++;
                }
                else{
                    e--;
                }
            }
            
        }
        
        vector<vector<int>> v1;
        for(auto x:ans){
            v1.push_back(x);
        }
        return v1;
        
        
    }
};