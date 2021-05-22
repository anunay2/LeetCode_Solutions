class Solution {
public:
    void printPaths(vector<vector<int>> &graph,vector<vector<int>> &ans,int node,int fin,vector<int> &temp){
        temp.push_back(node);
        if(node==fin){
            ans.push_back(temp);
            
        }
        for(auto x:graph[node]){
            printPaths(graph,ans,x,fin,temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        vector<vector<int>> ans;
        int n=graph.size();
        vector<bool> vis(n,false);
        vector<int> temp; 
        printPaths(graph,ans,0,n-1,temp);
        return ans;
    }
};