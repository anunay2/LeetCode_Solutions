class Solution {
public:
    bool withinLimits(int j,int i,int k){
        return (j>=i-k);
    }
    int maxResult(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> dp(n,0);
        //dp[i] = maximum score to reach till index i
        dp[0]=nums[0];
        priority_queue<pair<int,int>> p1;
        p1.push(make_pair(dp[0],0));
        for(int i=1; i<n; i++){
            dp[i]=nums[i];
            
            while(!withinLimits(p1.top().second,i,k)){
                p1.pop();
            }
            dp[i]+=p1.top().first;
            p1.push(make_pair(dp[i],i));
            
        }
        return dp[n-1];
    }
};