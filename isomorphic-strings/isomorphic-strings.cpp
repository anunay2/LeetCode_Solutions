class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> um1;
        set<char> value;
        for(int i=0; i<s.size(); i++){
            if(um1.find(s[i]) == um1.end()){
                if(value.find(t[i])==value.end()){
                     um1[s[i]] = t[i];
                    value.insert(t[i]);
                }
                else{
                    return false;
                }
              
            }
            else{
                if(um1[s[i]] == t[i] ){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};