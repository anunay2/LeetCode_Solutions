class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> leftmax,rightmin(nums.size(),nums.back());
        leftmax.push_back(nums[0]);
       
        for(int i=1;i<nums.size();i++){
            leftmax.push_back(nums[i]>leftmax[i-1]?nums[i]:leftmax[i-1]);
        }
        for(int i = nums.size()-2;i>=0;i--){
            rightmin[i] = rightmin[i+1]<nums[i]?rightmin[i+1]:nums[i];
        }
        
        // for(int i =0;i<nums.size();i++){
        //     cout<<leftmax[i]<<"\t"<<rightmin[i]<<"\n";
        // }
        
        int i=0;
        while(leftmax[i]>rightmin[i+1]){
            i++;
        }
        return i+1;
        
    }
};