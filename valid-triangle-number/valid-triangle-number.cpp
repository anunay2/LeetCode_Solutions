class Solution {
public:
    int triangleNumber(vector<int>& n1) {
        vector<int> nums;
        for(int i = 0;i<n1.size();i++){
            if(n1[i]!=0){
                nums.push_back(n1[i]);
            }
        }
        sort(nums.begin(),nums.end());
        int n = nums.size(),ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum = nums[i] + nums[j];
                //int in = lower_bound(nums.begin(),nums.end(),sum-1) - nums.end();
                auto itr = upper_bound(nums.begin(),nums.end(),sum-1);
                if(itr == nums.end()){
                     ans += (n-j-1);
                     //cout<<nums[i]<<"\t"<<nums[j]<<"\t"<<"\t"<<n-j<<"\n";
                }
                else{
                    int index = itr - nums.begin()-1;
                    //cout<<nums[i]<<"\t"<<nums[j]<<"\t"<<*itr<<"\t"<<index-j<<"\n";
                    ans += (index-j);
                }
               
            }
        }
        return ans;
    }
};