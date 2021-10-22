class Solution {
public:
    unordered_map<char,int> um1;
    bool static comp(pair<char,int> p1, pair<char,int> p2){
        return p1.second>p2.second;
    }
    string frequencySort(string s) {
        
        for(auto ch : s){
            um1[ch]++;
        }
        
        vector<pair<char,int>> freq;
        for(auto x : um1){
            freq.push_back({x.first,x.second});
        }
        
        sort(freq.begin(),freq.end(),comp);
        
        string ans;
        for(auto x: freq){
            for(int i=0;i<x.second;i++){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};