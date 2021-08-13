class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> um1;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            um1[s].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto x:um1){
            vector<int> index = x.second;
            vector<string> anagram;
            for(int in: index){
                anagram.push_back(strs[in]);
            }
            ans.push_back(anagram);
        }
        return ans;
    }
};