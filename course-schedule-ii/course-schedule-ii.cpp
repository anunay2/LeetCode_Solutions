class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n,vector<int>());
        vector<int> degree(n,0);
        
        for(auto &p : pre){
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++){
            if(degree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            
            n--;
            for(auto next : adj[curr]){
                if(--degree[next] == 0)
                    q.push(next);
            }
        }
        
        if (n==0){
            return ans;
        }
        vector<int> temp;
        return temp;
    }
};