class Solution {
public:
    vector<int> baap;
    vector<int> rank;
    int mod(int a){
        return a<0?-a:a;
    }
    bool static comp(pair<int, pair<int, int>> v1, pair<int, pair<int, int>> v2){
           return v1.second.second<v2.second.second;
    }
    int find_baap(int a){
        if(a==baap[a]){
            return a;
        }
        else{
            return baap[a] = find_baap(baap[a]);
        }
    }
    void uni(int a,int b){
        a = find_baap(a);
        b = find_baap(b);
      
        if(rank[a]>=rank[b]){
            baap[b] = a;
            rank[a]+=rank[b];
        }
        else{
            baap[a] = b;
            rank[b]+=rank[a];
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
       vector<pair<int, pair<int, int>>>  graph;
        int n = points.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int dist = mod(points[i][0] -points[j][0]) + mod(points[i][1]                                       - points[j][1]);
                graph.push_back(make_pair(i,make_pair(j,dist)));
            }
        }
        
        sort(graph.begin(),graph.end(),comp);
        
        //jitne vertices utne sets
        rank = vector<int>(n,0);
        for(int i=0;i<n;i++){
            baap.push_back(i);
        }
        int ans =0,count=0;
        for(auto edge: graph){
            if(find_baap(edge.first) != find_baap(edge.second.first)){
                uni(edge.first,edge.second.first);
                count++;
                ans += edge.second.second;
            }
            if(count==points.size()-1){
                return ans;
            }
            
        }
        return ans;
    }
};