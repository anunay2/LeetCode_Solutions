class Solution {
public:
    int flag=true;
    void dfs(vector<vector<int>> &grid2,int m, int n, int i, int j){
        if(i>=0 && j>=0 && i<m && j<n ){
            if(grid2[i][j]==2){
                grid2[i][j]=-2;
                dfs(grid2,m,n,i+1,j);
                dfs(grid2,m,n,i,j+1);
                dfs(grid2,m,n,i-1,j);
                dfs(grid2,m,n,i,j-1);
            }
            if(grid2[i][j]==1){
                flag=false;
                return;
            }
        }
        return;
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n= grid1[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid1[i][j]==1 && grid2[i][j]==1){
                    grid2[i][j]=2;
                }
            }
        }
        int ans=0;
        //if there are any adjacent 1 beside 2 in DFS then the island is not a subisland
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==2){
                    flag=true;
                    dfs(grid2,m,n,i,j);
                    if(flag==true){
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};