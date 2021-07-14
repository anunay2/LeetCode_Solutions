class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        //only one element
        if(h==0){
            return 0;
        }
        const int x = nums.size()-1;
        while(l<=h){
            int m = (l+h)/2;
         
            if(m==0){
                    if(nums[m] > nums[m+1]){
                        return m;
                    }
                    else{
                        l = m +1;
                    }
            }
            else if( m == x){
                    if(nums[m]>nums[m-1]){
                        return m;
                    }
                    else{
                        h = m-1;
                    }
            }
            else{
            
            if(nums[m]>nums[m-1] && nums[m]>nums[m+1]){
                        return m;
                    }
                    else if(nums[m-1]>nums[m] && nums[m]>nums[m+1] ){
                        h = m-1;                        
                    }
                    else{
                        l = m+1;
                    }
            }
    
          
        }
        return -1;
        
    }
};