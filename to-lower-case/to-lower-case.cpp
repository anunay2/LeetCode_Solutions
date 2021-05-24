class Solution {
public:
    bool isCapital(char ch){
        return ch>='A' && ch<='Z';
    }
    string toLowerCase(string s) {
        for(int i=0;i<s.size();i++){
            if(isCapital(s[i]))
                s[i]=s[i]+'a'-'A';
        }
        return s;
    }
};