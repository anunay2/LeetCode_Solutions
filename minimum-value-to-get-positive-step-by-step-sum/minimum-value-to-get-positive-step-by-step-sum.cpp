class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minVal = INT_MAX;
        int sum =0;
        for(auto x: nums){
            sum = sum +x;
            minVal = std::min(sum,minVal);
        }
        if(minVal>=0){
            return 1;
        }
        else{
         return minVal*-1 +1;   
        }
        return -1;
    }
};