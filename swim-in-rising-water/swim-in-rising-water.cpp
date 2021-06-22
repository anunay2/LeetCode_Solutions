class Solution {
public:
    int fun(vector<vector<int>>& grid,vector<vector<int>>&R,int n )
    {
        int dx[] = {0,-1,0,1};
        int dy[] = {-1,0,1,0};
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        while(!pq.empty())
        {
            vector<int>node = pq.top();
            pq.pop();
            if(R[node[1]][node[2]])
                continue;
            if(node[1] == n - 1 && node[2] == n - 1)
                return node[0];
            R[node[1]][node[2]] = 1;
            for(int i = 0; i < 4; i++)
            {
                int x = node[1] + dx[i];
                int y = node[2] + dy[i];
                if(x >= 0 && x < n && y >= 0 && y < n)
                {
                    vector<int>next_node = {max(node[0],grid[x][y]),x,y};
                    pq.push(next_node);
                }
            }
            
        }
        return -1;
        
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>R(n,vector<int>(n,0));
        return fun(grid,R,n);
        
        
        
    }
};