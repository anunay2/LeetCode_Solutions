class Solution {
public:
    bool within(int i,int j,int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int limit) {
        int cum[101][101];
        int n =matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int t1 = within(i-1,j,n,m)?cum[i-1][j]:0;
                int t2 = within(i,j-1,n,m)?cum[i][j-1]:0;
                int t3 = within(i-1,j-1,n,m)?cum[i-1][j-1]:0;
                cum[i][j] = t1 + t2 - t3 + matrix[i][j];
            }
        }
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                for(int k=i; k<n; k++){
                    for(int l=j; l<m; l++){
                        
                        int t1 = cum[k][l];
                        int t4 = within(i-1,j-1,n,m)?cum[i-1][j-1]:0;
                        int t3 = within(k,j-1,n,m)?cum[k][j-1]:0;
                        int t2 = within(i-1,l,n,m)?cum[i-1][l]:0;
                        
                        int sum = t1 - t3 - t2 + t4;
                        if(sum<=limit){
                            ans = max(ans,sum);
                        }
                    }
                }
                
            }
        }
        
        return ans;
    }
};