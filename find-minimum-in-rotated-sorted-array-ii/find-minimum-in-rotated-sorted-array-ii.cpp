class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int mid;
        int min1=INT_MAX;
        while(l<=r){
            mid=(l+r)/2;
             min1=min(nums[mid],min(min1,nums[l]));
            if(nums[l]<nums[mid]){
                //this half is sorted search in the other half after storing the minimin
                //min1=min(min1,nums[l]);
                l=mid+1;
            }
            else if(nums[mid]<nums[r]){
                //min1=min(nums[mid],min1);
                r=mid-1;
            }
            else{
                l++;
            }
        }
        return min1;
          
    }
};