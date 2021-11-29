class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int countLis = 0,l=1;
        vector<int> lis(nums.size(),1);
        vector<int> isPartOfLis(nums.size(),true);
        vector<int> ways(nums.size(),1);
        for(int i=1; i<nums.size(); i++){
            for(int j=i-1; j>=0;j--){
                if(nums[i]>nums[j]){
                    if(lis[j]+1>lis[i]){
                        lis[i] = lis[j] +1;
                        ways[i] = ways[j];
                    }
                    else if(lis[j]+1==lis[i]){
                        ways[i]+=ways[j];
                    }
                }
            }
            //cout<<lis[i]<<"\t";
            if(l==lis[i]){
                countLis+=ways[i];
            }
            else if(lis[i]>l){
                countLis = ways[i];
                l = lis[i];
            }
        }
        if(l==1){
            return nums.size();
        }       
        return countLis;
        
    }
};