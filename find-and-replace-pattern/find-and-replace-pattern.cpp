class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pat) {

        vector<string> ans;
        for(auto word:words){
            bool flag=true;
            for(int i=0;i<word.size();i++){
                for(int j=0;j<word.size();j++){
                    if(word[i]==word[j]){
                           if(pat[i]!=pat[j]){
                               flag=false;
                               break;
                           } 
                    }
                    else {
                        if(pat[i]==pat[j]){
                            flag=false;
                            break;
                        }
                    }
                }
            }
            if(flag==true)
                ans.push_back(word);
        }
        return ans;
    }
};