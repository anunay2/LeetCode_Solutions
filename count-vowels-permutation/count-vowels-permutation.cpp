class Solution {
public:
    const int M = 1e9 +7;
    int countVowelPermutation(int n) {
        unsigned long long int dp[2*10000+1][5];
        dp[0][0]=1,dp[0][1]=1,dp[0][2]=1,dp[0][3]=1,dp[0][4]=1;
        for(int i =1;i<n;i++){
            dp[i][0] = ((dp[i-1][2] + dp[i-1][1]) %M + dp[i-1][4])%M;
            dp[i][1] = (dp[i-1][2] + dp[i-1][0])%M;
            dp[i][2] = (dp[i-1][1] + dp[i-1][3])%M;
            dp[i][3] = dp[i-1][2]%M;
            dp[i][4] = (dp[i-1][2] + dp[i-1][3])%M;
        }
        int ans = 0;
        for(int i=0;i<5;i++){
            ans += dp[n-1][i];
            ans = ans %M;
        }
        return ans;
        
    }
};