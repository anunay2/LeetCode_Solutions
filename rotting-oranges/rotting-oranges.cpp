class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q1;
        bool flagFresh = false;
        for(int i=0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q1.push(make_pair(i,j));
                }
                if(grid[i][j] == 1){
                    flagFresh = true;
                }
            }
        }
        if(q1.empty() && flagFresh){
            return -1;
        }
        else if(q1.empty() && !flagFresh){
            return 0;
        }
        
        int t=0;
        int n = grid.size(),m = grid[0].size();
        while(!q1.empty()){
            int p = q1.size();
            for(int i=0;i<p;i++){
                pair<int,int> t = q1.front();
                q1.pop();
                vector<int> dx = {0,1,-1,0};
                vector<int> dy = {1,0,0,-1};
                for(int c = 0; c<4; c++){
                    int x = t.first + dx[c], y = t.second + dy[c];
                    if( x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
                        grid[x][y] = 2;
                        q1.push(make_pair(x,y));
                    }
                }
            }
            t++;
        }
        //cout<<t<<"\t";
         for(int i=0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return t-1;
        
    }
    
};