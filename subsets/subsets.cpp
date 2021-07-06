class Solution {
public:
    int min(int a,int b){
        return a<b?a:b;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = 1<<nums.size();
        vector<vector<int>> powsubset;
        for(int i=0; i<n; i++){
            vector<int> subset;
            //cout<<i<<"\t";
            for(int j=0; j< min(10,nums.size());j++){
              //cout<<(1<<j)<<"\t"<<i<<"\t"<<(1<<j & i)<<"\n";
                if(1<<j & i){
                    subset.push_back(nums[j]);
                }
            }
            powsubset.push_back(subset);
        }
        return powsubset;
    }
};