class Solution {
public:
    vector<int> baap;
    vector<int> rank;
    int find(int a){
        if(a == baap[a]){
            return a;
        }
        else{
            return baap[a] = find(baap[a]);
        }
    }
    
    void uni(int a, int b){
        a = find(a);
        b= find(b);
        if(rank[a]>=rank[b]){
            baap[b] = a;
            rank[a]++;
        }
        else{
            baap[a] = b;
            rank[b]++;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        rank = vector<int>(n,0);
        for(int i=0;i<n;i++){
            baap.push_back(i);
        }
        
        for(auto &v : allowedSwaps){
            uni(v[0],v[1]);
        }
        
        vector<unordered_multiset<int>> subs(n);
        for(int i=0;i<n;i++){
            subs[find(i)].insert(source[i]);
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!subs[baap[i]].count(target[i])){
                cnt++;
            }
            else{
                subs[baap[i]].erase(subs[baap[i]].find(target[i]));
            }
        }
        return cnt;
    }
};