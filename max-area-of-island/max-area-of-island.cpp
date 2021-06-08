class Solution {
public:
    int max1=0,ans=0;
    void DFS(int row,int col,int i,int j,vector<vector<int>> &grid){
        
        if(i>=0 && i<row && j>=0 && j<col && grid[i][j]==1){
            grid[i][j]=-1;
            ans++;
            max1=max(ans,max1);
            DFS(row,col,i+1,j,grid);
            DFS(row,col,i,j+1,grid);
            DFS(row,col,i-1,j,grid);
            DFS(row,col,i,j-1,grid);
            
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        if(row==0){
            return 0;
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1)
                    ans=0;
                    DFS(row,col,i,j,grid);
            }
        }
        return max1;
    }
};