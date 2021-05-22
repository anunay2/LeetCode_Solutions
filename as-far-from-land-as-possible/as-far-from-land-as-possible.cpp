class Solution {
public:
    void DFS(int i,int j,vector<vector<int>> &grid,int dist){
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size()
          && (grid[i][j]>dist || grid[i][j]==0)){
            grid[i][j]=dist;
            DFS(i,j-1,grid,dist+1);
            DFS(i,j+1,grid,dist+1);
            DFS(i+1,j,grid,dist+1);
            DFS(i-1,j,grid,dist+1);
        }
    }
    int maxDistance(vector<vector<int>>& grid) {
        //simultaneous BFS from the land
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    DFS(i,j,grid,1);
                }
            }
        }
        int max_dist=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                //cout<<grid[i][j]<<"\t";
                if(grid[i][j]!=1)
                    max_dist=max(max_dist,grid[i][j]);
            }
            //cout<<"\n";
        }
        return max_dist-1;
        
    }
};