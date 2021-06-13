class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> m1;
        for(string word : words){
            for(char ch : word){
                m1[ch]++;
            }
        }
        int n = words.size();
        for(auto x: m1){
            if(x.second%n==0){
                continue;
            }
            return false;
        }
        return true;
    }
};